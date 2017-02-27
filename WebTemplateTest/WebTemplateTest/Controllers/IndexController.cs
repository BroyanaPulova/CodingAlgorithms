using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace WebTemplateTest.Controllers
{
    public class IndexController : Controller
    {
        // GET: Index
        public ActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public ActionResult Codes()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult ShanonFano()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult Hufman()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult LinearCodes()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult SystematicForm()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult SystematicallyDecoding()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult Hemming()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult Meggitt()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult ReedMuller()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult HemmingTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult HufmanTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult LinearCodesTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult MeggittTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult ReedMullerTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult ShanonFanoTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult SystematicallyDecodingTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult SystematicFormTheory()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult HemmingExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult HufmanExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult LinearCodesExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult MeggittExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult ReedMullerExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult ShanonFanoExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult SystematicallyDecodingExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult SystematicFormExample()
        {
            return PartialView();
        }

        [HttpGet]
        public ActionResult Questions()
        {
            return PartialView();
        }
    }
}