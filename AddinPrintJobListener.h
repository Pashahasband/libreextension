#pragma once
#include <stdio.h>
#include <string>
#include <fstream>
#include "addon.hxx"

#include <com/sun/star/view/XPrintJob.hpp>
#include <com/sun/star/view/XPrintJobListener.hpp>
#include <com/sun/star/view/XPrintJobBroadcaster.hpp>
#include <cppuhelper/implbase1.hxx>

namespace css = com::sun::star;
/* Close listener */
class AddinPrintJobListener : public ::cppu::WeakImplHelper1<css::view::XPrintJobListener>
{
private:
	Addon *const owner;

public:
	AddinPrintJobListener(Addon* const _owner);
	virtual void SAL_CALL disposing(const css::lang::EventObject& aEventObj) throw(css::uno::RuntimeException);
	virtual void SAL_CALL printJobEvent(const css::view::PrintJobEvent& rEvent ) throw(css::uno::RuntimeException);
};