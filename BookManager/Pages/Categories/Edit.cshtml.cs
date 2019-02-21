using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using Microsoft.EntityFrameworkCore;

namespace BookManager.Pages.Categories
{
    public class EditModel : PageModel
    {
        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Category Entry { get; set; }
        readonly string to = "/Categories/Index";
        readonly BookDbContext db;

        public EditModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
            Entry = await db.Categories.FindAsync(id);
            if (Entry == null)
                return RedirectToPage("/Error", new { to, err = $"Category with id = {id} does not exist..." });
            return Page();
        }

        public async Task<IActionResult> OnPostAddAsync()
        {
            if (!ModelState.IsValid)
                return Page();
            if (!string.IsNullOrWhiteSpace(Entry.Name) &&
                !string.IsNullOrWhiteSpace(Entry.RowVersion)
                )
            {
                db.Categories.Update(Entry);
                await db.SaveChangesAsync();
                Result = $"Category id = {Entry.Id} save to Db.";
            }
            return RedirectToPage("./Edit", new { id = Entry.Id });
        }
    }
}
