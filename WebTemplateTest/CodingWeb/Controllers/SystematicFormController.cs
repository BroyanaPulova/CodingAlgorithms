using CodeWrapper;
using CodingWeb.Common;
using CodingWeb.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class SystematicFormController : BaseCodingControler
    {
        // GET: SystematicForm
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

        [HttpPost]
        public string Encode(MatrixCodeModel model)
        {
            return CodingHelper.SystemFormCheckMatrix(model.M, model.N, model.ConvertToDecMatrix());
        }
    }
}