// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_NODE_INCLUDES_H_
#define ATOM_COMMON_NODE_INCLUDES_H_

#include "base/logging.h"

// Include common headers for using node APIs.

#ifdef NODE_SHARED_MODE
#define BUILDING_NODE_EXTENSION
#endif

// The following define makes sure that we do not include the macros
// again. But we still need the tracing functions, so declaring them.
#define SRC_TRACING_TRACE_EVENT_H_

#pragma push_macro("ASSERT")
#pragma push_macro("CHECK")
#pragma push_macro("CHECK_EQ")
#pragma push_macro("CHECK_GE")
#pragma push_macro("CHECK_GT")
#pragma push_macro("CHECK_LE")
#pragma push_macro("CHECK_LT")
#pragma push_macro("CHECK_NE")
#pragma push_macro("DISALLOW_COPY_AND_ASSIGN")
#pragma push_macro("LIKELY")
#pragma push_macro("NO_RETURN")
#pragma push_macro("UNLIKELY")

#undef ASSERT
#undef CHECK
#undef CHECK_EQ
#undef CHECK_GE
#undef CHECK_GT
#undef CHECK_LE
#undef CHECK_LT
#undef CHECK_NE
#undef DISALLOW_COPY_AND_ASSIGN
#undef LIKELY
#undef NO_RETURN
#undef UNLIKELY

#undef debug_string    // This is defined in macOS SDK in AssertMacros.h.
#undef require_string  // This is defined in macOS SDK in AssertMacros.h.
#include "env-inl.h"
#include "env.h"
#include "node.h"
#include "node_buffer.h"
#include "node_internals.h"
#include "node_options.h"
#include "node_platform.h"

#pragma pop_macro("ASSERT")
#pragma pop_macro("CHECK")
#pragma pop_macro("CHECK_EQ")
#pragma pop_macro("CHECK_GE")
#pragma pop_macro("CHECK_GT")
#pragma pop_macro("CHECK_LE")
#pragma pop_macro("CHECK_LT")
#pragma pop_macro("CHECK_NE")
#pragma pop_macro("DISALLOW_COPY_AND_ASSIGN")
#pragma pop_macro("LIKELY")
#pragma pop_macro("NO_RETURN")
#pragma pop_macro("UNLIKELY")

namespace node {
namespace tracing {

class TraceEventHelper {
 public:
  static v8::TracingController* GetTracingController();
  static node::tracing::Agent* GetAgent();
  static void SetAgent(node::tracing::Agent* agent);
};

}  // namespace tracing
}  // namespace node

#endif  // ATOM_COMMON_NODE_INCLUDES_H_
