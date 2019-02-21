using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using Microsoft.EntityFrameworkCore;

namespace BookManager.Pages.Books
{
    public class EditModel : PageModel
    {
        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Book Entry { get; set; }
        readonly string to = "/Books/Index";
        readonly BookDbContext db;
        public IList<Author> Authors { get; private set; }
        public IList<Category> Categories { get; private set; }

        public EditModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
            Entry = await db.Books.Include("Author").Include("Category")
                .FirstOrDefaultAsync(i => i.Id == id);
            if (Entry == null)
                return RedirectToPage("/Error", new { to, err = $"Book with id = {id} does not exist..." });

            Authors = await db.Authors.AsNoTracking().ToListAsync();
            Categories = await db.Categories.AsNoTracking().ToListAsync();

            return Page();
        }

        public async Task<IActionResult> OnPostAddAsync()
        {
            if (!ModelState.IsValid)
                return Page();
            if (!string.IsNullOrWhiteSpace(Entry.Title) &&
                Entry.Uri != null &&
                Entry.CategoryId > 0 &&
                Entry.AuthorId > 0
                )
            {
                db.Books.Update(Entry);
                await db.SaveChangesAsync();
                Result = $"Book id = {Entry.Id} save to Db.";
            }
            return RedirectToPage("./Edit", new {id = Entry.Id });
        }
    }
}
