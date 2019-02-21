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
    public class DeleteModel : PageModel
    {
        public Category Entry { get; set; }

        readonly BookDbContext db;

        public DeleteModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
            Entry = await db.Categories.FindAsync(id);
            if (Entry == null)
                return RedirectToPage("./Index");
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int id)
        {
            var m = await db.Categories.FindAsync(id);
            db.Categories.Remove(m);
            await db.SaveChangesAsync();
            return RedirectToPage("./Index");
        }
    }
}
