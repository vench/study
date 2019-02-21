using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;

namespace BookManager.Pages
{
    public class IndexModel : PageModel
    {
        public bool Hidden { get; set; }
        public string Result { get; set; }
        BookDbContext db;


        public IndexModel(BookDbContext ctx) {
            db = ctx;
            Hidden = true;
            Result = "";
        }

        public void OnGet()
        {


        }

        public void OnGetTryDropDbAsync()
        {
            Result = "Confirm deleting the whole database. (handler: OnGetTryDropDbAsync)";
            Hidden = false;
        }

        public void OnGetCancel() { Hidden = true; }

        public async Task OnGetDropDbAsync()
        {
            await db.Database.EnsureDeletedAsync();
            Hidden = true;
            Result = @"Database is destroyed. Check up in C:\Users\YourName\";
        }
    }

}
