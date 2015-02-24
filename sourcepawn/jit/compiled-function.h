// vim: set sts=2 ts=8 sw=2 tw=99 et:
// 
// Copyright (C) 2006-2015 AlliedModders LLC
// 
// This file is part of SourcePawn. SourcePawn is free software: you can
// redistribute it and/or modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.
//
// You should have received a copy of the GNU General Public License along with
// SourcePawn. If not, see http://www.gnu.org/licenses/.
//
#ifndef _INCLUDE_SOURCEPAWN_JIT2_FUNCTION_H_
#define _INCLUDE_SOURCEPAWN_JIT2_FUNCTION_H_

#include <sp_vm_types.h>
#include <am-fixedarray.h>
#include <am-refcounting.h>

namespace sp {

using namespace ke;

struct LoopEdge
{
  uint32_t offset;
  int32_t disp32;
};

class CompiledFunction
{
 public:
  CompiledFunction(void *entry_addr, cell_t pcode_offs, FixedArray<LoopEdge> *edges);
  ~CompiledFunction();

 public:
  void *GetEntryAddress() const {
    return entry_;
  }
  cell_t GetCodeOffset() const {
    return code_offset_;
  }
  uint32_t NumLoopEdges() const {
    return edges_->length();
  }
  const LoopEdge &GetLoopEdge(size_t i) const {
    return edges_->at(i);
  }

 private:
  void *entry_;
  cell_t code_offset_;
  AutoPtr<FixedArray<LoopEdge>> edges_;
};

}

#endif //_INCLUDE_SOURCEPAWN_JIT2_FUNCTION_H_
