using CodeWrapper;
using CodingWeb.Common;
using CodingWeb.Models;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CodingWeb.Controllers
{
    public class LinearCodesController : BaseCodingControler
    {
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

        public string Encode(MatrixCodeModel model)
        {
            int[] matrix = model.ConvertToDecMatrix();

            //var m = 3;
            //var n = 7;
            //var arrays = new int[] { 15, 51, 85 };

            return CodingHelper.SpectreLinearCode(model.M, model.N, matrix);
        }
    }
}