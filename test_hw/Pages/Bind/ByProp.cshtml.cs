using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace test_hw.Pages.Bind
{
    public class ByPropModel : PageModel
    {
        [BindProperty]
        public string Verb { get; set; }
        [BindProperty]
        public string Noun { get; set; }

        public void OnPost()
        {
            ViewData["all"] = $"You must {Verb} {Noun}";
        }
    }
}
