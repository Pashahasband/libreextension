#include "AddinPrintJobListener.h"
#include <cppuhelper/bootstrap.hxx>

using rtl::OUString;
using namespace com::sun::star::uno;
using namespace com::sun::star::frame;
using namespace com::sun::star::awt;
using com::sun::star::beans::PropertyValue;
using com::sun::star::util::URL;

AddinPrintJobListener::AddinPrintJobListener(Addon* const _owner)
	: owner(_owner) {}
// com/sun/star/lang/XEventListener
void SAL_CALL AddinPrintJobListener::disposing(const com::sun::star::lang::EventObject& aEventObj) throw(RuntimeException)
{
}

void SAL_CALL AddinPrintJobListener::printJobEvent(const com::sun::star::view::PrintJobEvent& rEvent) throw(RuntimeException)
{
	std::ofstream out{R"(C:\test\log.txt)", std::ios::app};
	if (out.is_open())
	{
		out << "AddinPrintJobListener::printJobEvent" << std::endl;
		out << rEvent.State << std::endl;
	}
	out.close();
	Reference<com::sun::star::view::XPrintJob> xPrint(rEvent.Source, UNO_QUERY);
	xPrint->cancelJob();
}

