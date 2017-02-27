using System.Web.Mvc;

namespace CodingWeb.Common
{
    public abstract class BaseCodingControler : Controller
    {
        abstract public ActionResult ShortDetails();
        abstract public ActionResult Example();
        abstract public ActionResult Theory();
    }
}