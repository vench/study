using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using BookManager.Hint;

namespace BookManager.Pages.Authors
{
    public class CreateModel : PageModel
    {
        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Author Entry { get; set; }

        readonly BookDbContext db;

        public CreateModel(BookDbContext ctx)
        {
            db = ctx;
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
                db.Authors.Add(Entry);
                await db.SaveChangesAsync();
                Result = $"Author id = {Entry.Id} added to Db. (handler: OnPostAddAsync)";
            }
            return RedirectToPage("./Index");
        }
    }
}
