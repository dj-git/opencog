/*
 * opencog/embodiment/Learning/RewritingRules/hillclimbing_perception_reduction.cc
 *
 * Copyright (C) 2007-2008 Nil Geisweiller
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "comboreduct/reduct/reduct.h"
#include "hillclimbing_perception_reduction.h"
#include "comboreduct/reduct/meta_rules.h"
#include "comboreduct/reduct/general_rules.h"
#include "comboreduct/reduct/perception_rules.h"

namespace reduct
{

const rule& hillclimbing_perception_reduction()
{
    static iterative r;

    r = iterative(sequential(//perception
                      downwards(reduce_reflexive()),
                      downwards(reduce_irreflexive()),
                      upwards(reorder_commutative())
                  ));

    return r;
}
}

