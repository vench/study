using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using BookManager.Hint;

namespace BookManager.Pages.Categories
{
    public class CreateModel : PageModel
    {
        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Category Entry { get; set; }

        readonly BookDbContext db;

        public CreateModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnPostAddAsync()
        {
            if (!ModelState.IsValid)
                return Page();
            if (!string.IsNullOrWhiteSpace(Entry.Name) &&
                !string.IsNullOrWhiteSpace(Entry.RowVersion)
                )
            {
                db.Categories.Add(Entry);
                await db.SaveChangesAsync();
                Result = $"Category id = {Entry.Id} added to Db. (handler: OnPostAddAsync)";
            }
            return RedirectToPage("./Index");
        }
    }
}
