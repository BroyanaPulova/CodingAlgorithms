using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace WebTemplateTest.Controllers
{
    public class QuestionsController : Controller
    {
        // GET: Questions
        public ActionResult Questions()
        {
            return View();
        }
    }
}