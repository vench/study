using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using test_hw.Model;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;

namespace test_hw.Pages.Db
{
    public class IndexModel : PageModel
    {
        readonly MsgDbContext db;

        public IndexModel(MsgDbContext ctx)
        {
            db = ctx;
            db.Database.EnsureCreated();
        }

        [TempData]
        public string Result { get; set; }
        [BindProperty]
        public Message Message { get; set; }
        public IList<Message> Messages { get; private set; }

        public async Task OnGetAsync()
        {
            Messages = await db.Messages.AsNoTracking().ToListAsync();
        }

        public async Task<IActionResult> OnPostAddAsync()
        {
            if (!ModelState.IsValid)
                return Page();
            if (!string.IsNullOrWhiteSpace(Message.Text))
            {
                db.Messages.Add(Message);
                await db.SaveChangesAsync();
                Result = $"Message id = {Message.Id} added to Db. (handler: OnPostAddAsync)";
            }
            return RedirectToPage();
        }
    }
}
