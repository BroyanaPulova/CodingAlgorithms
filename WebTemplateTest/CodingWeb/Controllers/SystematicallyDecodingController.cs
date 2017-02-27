using CodingWeb.Common;
using CodingWeb.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class SystematicallyDecodingController : BaseCodingControler
    {
        // GET: SystematicallyDecoding
        public override ActionResult ShortDetails()
        {
            return View();
        }

        public override ActionResult Example()
        {
            return View();
        }

        public override ActionResult Theory()
        {
            return View();
        }
        
        public string Decode(SyndromDecode model)
        {
            return CodeWrapper.CodingHelper.SyndromeDecode(model.N, model.M, model.MinimalLength, model.ConvertToDecMatrix(), model.YInput);
        }
    }
}