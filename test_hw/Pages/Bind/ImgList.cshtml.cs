using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.FileProviders;

namespace test_hw.Pages.Bind
{
    public class ImgListModel : PageModel
    {
        public string Msg { get; set; } // Выполняет роль Model в архитектуре MVC
        public List<string> ListUrl { get; set; }
        [TempData]
        public bool ImgFlag { get; set; }

        public ImgListModel()
        {
            Msg = "Creating ImgListModel. ";
        }
        public void OnGet()
        {
            Msg += "ImgListModel.OnGet handler. ";
        }
        public IActionResult OnGetShowImg()
        {
            ImgFlag = !ImgFlag;
            Msg += "ImgListModel.OnGetShowImg handler.";
            ListUrl = new List<string>();
            var provider = new PhysicalFileProvider(@"/home/vench/Projects/test_hw/test_hw/wwwroot/images/");
            foreach (var file in provider.GetDirectoryContents(""))
                ListUrl.Add($"/images/{file.Name}");
            return Page();
        }
    }
}
