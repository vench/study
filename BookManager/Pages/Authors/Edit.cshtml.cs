using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using Microsoft.EntityFrameworkCore;

namespace BookManager.Pages.Authors
{
    public class EditModel : PageModel
    {
        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Author Entry { get; set; }
        readonly string to = "/Authors/Index";
        readonly BookDbContext db;

        public EditModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
            Entry = await db.Authors.FindAsync(id) ;
            if (Entry == null)
                return RedirectToPage("/Error", new { to, err = $"Author with id = {id} does not exist..." });
            return Page();
        }

        public async Task<IActionResult> OnPostAddAsync()
        {
            if (!ModelState.IsValid)
                return Page();
            if (!string.IsNullOrWhiteSpace(Entry.Email) &&
                !string.IsNullOrWhiteSpace(Entry.ForeName) &&
                !string.IsNullOrWhiteSpace(Entry.LastName) 
                )
            {
                db.Authors.Update(Entry);
                await db.SaveChangesAsync();
                Result = $"Author id = {Entry.Id} save to Db.";
            }
            return RedirectToPage("./Edit", new { id = Entry.Id });
        }
    }
}
