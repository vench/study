using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BookManager.Pages
{
    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public class ErrorModel : PageModel
    {
        public string Err { get; set; }
        [BindProperty]
        public string To { get; set; }

        public IActionResult OnGet(string to, string err)
        {
            To = to;
            Err = err;
            return Page();
        }
        public IActionResult OnPost()
        {
            To = To ?? "/Index";
            return RedirectToPage(To);
        }
    }
}
