using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace test_hw.Pages.Bind
{

    public class Contact
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
    }

    public class ByObjModel : PageModel
    {
        [BindProperty]
        public List<Contact> Contacts { get; set; }
        public string Msg { get; set; }

        public void OnGet()
        {
            Contacts = new List<Contact>
            {
                new Contact { Id = 1, Name = "Alex Black", Email = "a@avalon.ru" },
                new Contact { Id = 2, Name = "Peter Pann", Email = "p@gmail.com" },
                new Contact { Id = 3, Name = "Joy Amore", Email = "joy@yahoo.com" },
            };
        }
        public void OnPost()
        {
            Msg = "List of Contact was successfully submitted";
        }
    }
}
