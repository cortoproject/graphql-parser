/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include <graphql/parser/GraphQLAstToJSON.h>

#include <cstring>

#include "../JsonVisitor.h"
#include "../AstNode.h"


const char *graphql_ast_to_json(const struct GraphQLAstNode *node)
{
  facebook::graphql::ast::visitor::JsonVisitor visitor;
  reinterpret_cast<const facebook::graphql::ast::Node *>(node)->accept(&visitor);
  return strdup(visitor.getResult().c_str());
}
