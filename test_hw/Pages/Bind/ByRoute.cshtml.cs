using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace test_hw.Pages.Bind
{
    public class ByRouteModel : PageModel
    {
        public void OnGet(string txt) { ViewData["key"] = $"{txt}"; }

        public void OnPost(string txt) { ViewData["key"] = $"{txt}"; }
    }
}
