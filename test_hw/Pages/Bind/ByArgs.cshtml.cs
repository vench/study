using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace test_hw.Pages.Bind
{
    public class ByArgsModel : PageModel
    {
        public void OnGet()
        {
        }

        public void OnPost(string verb, string noun)
        {
            ViewData["all"] = $"You must {verb} {noun}";
        }
    }
}
