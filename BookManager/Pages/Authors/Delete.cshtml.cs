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
    public class DeleteModel : PageModel
    {
        public Author Entry { get; set; }

        readonly BookDbContext db;

        public DeleteModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
            Entry = await db.Authors.FindAsync(id);
            if (Entry == null)
                return RedirectToPage("./Index");
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int id)
        {
            var m = await db.Authors.FindAsync(id);
            db.Authors.Remove(m);
            await db.SaveChangesAsync();
            return RedirectToPage("./Index");
        }
    }
}
