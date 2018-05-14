#pragma region License
/*
 * This file is part of the Boomerang Decompiler.
 *
 * See the file "LICENSE.TERMS" for information on usage and
 * redistribution of this file, and for a DISCLAIMER OF ALL
 * WARRANTIES.
 */
#pragma endregion License
#include "ExpSSAXformer.h"


#include "boomerang/db/exp/Location.h"
#include "boomerang/db/exp/RefExp.h"
#include "boomerang/db/proc/UserProc.h"
#include "boomerang/util/Log.h"


ExpSsaXformer::ExpSsaXformer(UserProc* p)
    : m_proc(p)
{
}


SharedExp ExpSsaXformer::postModify(const std::shared_ptr<RefExp>& exp)
{
    QString sym = m_proc->lookupSymFromRefAny(exp);

    if (!sym.isNull()) {
        return Location::local(sym, m_proc);
    }

    // We should not get here: all locations should be replaced with Locals or Parameters
    LOG_ERROR("Could not find local or parameter for %1!!", exp);
    return exp->getSubExp1(); // At least strip off the subscript
}