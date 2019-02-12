using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace test_hw.Pages.Bind
{
    public class ByCollModel : PageModel
    {
        [BindProperty]
        public string[] Ch { get; set; } = new string[3];
    }
}
