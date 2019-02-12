using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace test_hw.Pages.Bind
{
    public class ByHandModel : PageModel
    {
        public void OnGet()
        {
        }

        public void OnPost()
        {
            var verb = Request.Form["verb"];
            var noun = Request.Form["noun"];
            ViewData["all"] = $"You must {verb} {noun}";
        }
    }
}
