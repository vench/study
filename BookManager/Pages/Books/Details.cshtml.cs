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
    public class DetailsModel : PageModel
    {

        public Book Entry { get; set; }
        readonly string to = "/Authors/Index";
        readonly BookDbContext db;

        public DetailsModel(BookDbContext ctx)
        {
            db = ctx;
        }

        public async Task<IActionResult> OnGetAsync(int id)
        {
            Entry = await db.Books.Include("Author").Include("Category")
                .FirstOrDefaultAsync(i => i.Id == id); 
            if (Entry == null)
                return RedirectToPage("/Error", new { to, err = $"Author with id = {id} does not exist..." });
            return Page();
        }
    }
}
