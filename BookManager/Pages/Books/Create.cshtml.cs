using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using BookManager.Hint;
using Microsoft.EntityFrameworkCore;

namespace BookManager.Pages.Books
{
    public class CreateModel : PageModel
    {

        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Book Entry { get; set; }
        public IList<Author> Authors { get; private set; }
        public IList<Category> Categories { get; private set; }
        readonly BookDbContext db;

        public CreateModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
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
                db.Books.Add(Entry);
                await db.SaveChangesAsync();
                Result = $"Book id = {Entry.Id} added to Db. (handler: OnPostAddAsync)";
            }
            return RedirectToPage("./Index");
        }
    }
}
