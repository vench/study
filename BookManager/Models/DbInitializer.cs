using System;
namespace BookManager.Models
{
    public static class DbInitializer
    {
        public static void Seed(BookDbContext db)
        {
            if( !db.Database.EnsureCreated())
                return;   // DB has been seeded

            var cats = new Category[]
            {
                new Category{Name="AspNet"},new Category{Name="JavaScript"},new Category{Name="CSharp"},
                new Category{Name="EF"},new Category{Name="SQL"},new Category{Name="PowerShell"},
            };
            foreach (var x in cats)
                db.Categories.Add(x);
            db.SaveChanges();

            var authors = new Author[]
            {
                new Author{LastName="Albahari",ForeName="Josef",Email="albahari@gmail.com"},
                new Author{LastName="Reynders",ForeName="Fanie",Email="fanie@gmail.com"},
                new Author{LastName="Smith",ForeName="Jon",Email="smith@gmail.com"},
                new Author{LastName="Lock",ForeName="Andrew",Email="lock@gmail.com"},
                new Author{LastName="Fagerberg",ForeName="Jonas",Email="jonas@gmail.com"},
                new Author{LastName="Freeman",ForeName="Adam",Email="freeman@gmail.com"},
                new Author{LastName="Schwichtenberg",ForeName="Holger",Email="albahari@gmail.com"},
                new Author{LastName="Najim",ForeName="Maxime",Email="maxime@gmail.com"},
                new Author{LastName="Ramos",ForeName="Ruben Oliva",Email="ramos@gmail.com"},
                new Author{LastName="Beighley",ForeName="Lynn",Email="beighley@gmail.com"},
                new Author{LastName="Williams",ForeName="Gordon",Email="gordon@gmail.com"},
                new Author{LastName="Resig",ForeName="John",Email="resig@gmail.com"},

            };
            foreach (var x in authors)
                db.Authors.Add(x);
            db.SaveChanges();

            var books = new Book[]
            {
                new Book{Title="C#7.0 in a Nutshell",Uri=new Uri("http://shop.oreilly.com/product/0636920083634.do",UriKind.Absolute),CategoryId=3,AuthorId=1},
                new Book{Title="LINQ pocket reference",Uri=new Uri("http://shop.oreilly.com/product/9780596519254.do",UriKind.Absolute),CategoryId=3,AuthorId=1},
                new Book{Title="C#7.0 pocket reference",Uri=new Uri("http://shop.oreilly.com/product/0636920084211.do",UriKind.Absolute),CategoryId=3,AuthorId=1},
                new Book{Title="Modern API Design with ASP.NET Core 2",Uri=new Uri("https://www.apress.com/de/book/9781484235188",UriKind.Absolute),CategoryId=1,AuthorId=2},
                new Book{Title="RESTful Services with ASP.NET Web API",Uri=new Uri("http://shop.oreilly.com/product/110000477.do",UriKind.Absolute),CategoryId=1,AuthorId=2},
                new Book{Title="Entity Framework Core in Action",Uri=new Uri("https://www.manning.com/books/entity-framework-core-in-action",UriKind.Absolute),CategoryId=4,AuthorId=3},
                new Book{Title="ASP.NET MVC 5",Uri=new Uri("https://www.amazon.co.uk/ASP-NET-MVC-Building-Tactical-Guidebook/dp/1535167866",UriKind.Absolute),CategoryId=1,AuthorId=5},
                new Book{Title="ASP.NET Core 2.0 MVC And Razor Pages",Uri=new Uri("https://www.manning.com/books/asp-net-core-in-action",UriKind.Absolute),CategoryId=1,AuthorId=5},
                new Book{Title="C# For Beginners: The tactical guidebook",Uri=new Uri("https://www.amazon.com/Beginners-tactical-guidebook-CSharp-coding-ebook/dp/B017OAFR8I",UriKind.Absolute),CategoryId=3,AuthorId=5},
                new Book{Title="Pro ASP.NET Core MVC 2",Uri=new Uri("https://www.waterstones.com/book/pro-asp-net-core-mvc-2/adam-freeman/9781484231494",UriKind.Absolute),CategoryId=1,AuthorId=6},
                new Book{Title="Pro ASP.NET MVC 5",Uri=new Uri("https://www.waterstones.com/book/pro-asp-net-mvc-5/adam-freeman/9781430265290",UriKind.Absolute),CategoryId=1,AuthorId=6},
                new Book{Title="Modern Data Access with Entity Framework Core",Uri=new Uri("https://www.amazon.com/Modern-Data-Access-Entity-Framework/dp/1484235517",UriKind.Absolute),CategoryId=4,AuthorId=7},
                new Book{Title="Essential PowerShell",Uri=new Uri("https://www.oreilly.com/library/view/essential-powershell/9780768684391/",UriKind.Absolute),CategoryId=6,AuthorId=7},
                new Book{Title="Why Isomorphic JavaScript?",Uri=new Uri("https://www.oreilly.com/web-platform/free/why-isomorphic-javascript.csp",UriKind.Absolute),CategoryId=2,AuthorId=8},
                new Book{Title="Universal JavaScript with React",Uri=new Uri("https://www.packtpub.com/web-development/universal-javascript-react-node-and-redux-video",UriKind.Absolute),CategoryId=2,AuthorId=8},
                new Book{Title="Eloquent JavaScript",Uri=new Uri("https://eloquentjavascript.net/",UriKind.Absolute),CategoryId=2,AuthorId=9},
                new Book{Title="Internet of Things Programming with JavaScript",Uri=new Uri("https://www.packtpub.com/web-development/internet-things-programming-javascript",UriKind.Absolute),CategoryId=2,AuthorId=9},
                new Book{Title="Jumpstarting Javascript",Uri=new Uri("http://shop.oreilly.com/product/0636920115540.do",UriKind.Absolute),CategoryId=2,AuthorId=10},
                new Book{Title="Head First SQL",Uri=new Uri("http://shop.oreilly.com/product/9780596526849.do",UriKind.Absolute),CategoryId=5,AuthorId=10},
                new Book{Title="Easy Embedded JavaScript Programming",Uri=new Uri("http://shop.oreilly.com/product/0636920031246.do",UriKind.Absolute),CategoryId=2,AuthorId=11},
                new Book{Title="Secrets of the JavaScript Ninja",Uri=new Uri("https://www.manning.com/books/secrets-of-the-javascript-ninja",UriKind.Absolute),CategoryId=2,AuthorId=12},
                new Book{Title="Pro JavaScript Techniques",Uri=new Uri("https://www.apress.com/us/book/9781590597279",UriKind.Absolute),CategoryId=2,AuthorId=12},
            };
            foreach (var x in books)
                db.Books.Add(x);
            db.SaveChanges();
        }
    }
}
