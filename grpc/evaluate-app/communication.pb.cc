// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: communication.proto

#include "communication.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
        template <typename>
PROTOBUF_CONSTEXPR FormulaRequest::FormulaRequest(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.formula_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_.data_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct FormulaRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FormulaRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~FormulaRequestDefaultTypeInternal() {}
  union {
    FormulaRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FormulaRequestDefaultTypeInternal _FormulaRequest_default_instance_;
        template <typename>
PROTOBUF_CONSTEXPR FormulaResponse::FormulaResponse(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.result_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct FormulaResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FormulaResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~FormulaResponseDefaultTypeInternal() {}
  union {
    FormulaResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FormulaResponseDefaultTypeInternal _FormulaResponse_default_instance_;
static ::_pb::Metadata file_level_metadata_communication_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_communication_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_communication_2eproto = nullptr;
const ::uint32_t TableStruct_communication_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::FormulaRequest, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::FormulaRequest, _impl_.formula_),
    PROTOBUF_FIELD_OFFSET(::FormulaRequest, _impl_.data_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::FormulaResponse, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::FormulaResponse, _impl_.result_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::FormulaRequest)},
        {10, -1, -1, sizeof(::FormulaResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::_FormulaRequest_default_instance_._instance,
    &::_FormulaResponse_default_instance_._instance,
};
const char descriptor_table_protodef_communication_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\023communication.proto\"/\n\016FormulaRequest\022"
    "\017\n\007formula\030\001 \001(\t\022\014\n\004data\030\002 \001(\t\"!\n\017Formul"
    "aResponse\022\016\n\006result\030\001 \001(\t2H\n\020FormulaEval"
    "uator\0224\n\017EvaluateFormula\022\017.FormulaReques"
    "t\032\020.FormulaResponseb\006proto3"
};
static ::absl::once_flag descriptor_table_communication_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_communication_2eproto = {
    false,
    false,
    187,
    descriptor_table_protodef_communication_2eproto,
    "communication.proto",
    &descriptor_table_communication_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_communication_2eproto::offsets,
    file_level_metadata_communication_2eproto,
    file_level_enum_descriptors_communication_2eproto,
    file_level_service_descriptors_communication_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_communication_2eproto_getter() {
  return &descriptor_table_communication_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_communication_2eproto(&descriptor_table_communication_2eproto);
// ===================================================================

class FormulaRequest::_Internal {
 public:
};

FormulaRequest::FormulaRequest(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:FormulaRequest)
}
FormulaRequest::FormulaRequest(const FormulaRequest& from) : ::google::protobuf::Message() {
  FormulaRequest* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.formula_){},
      decltype(_impl_.data_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  _impl_.formula_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.formula_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_formula().empty()) {
    _this->_impl_.formula_.Set(from._internal_formula(), _this->GetArenaForAllocation());
  }
  _impl_.data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.data_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_data().empty()) {
    _this->_impl_.data_.Set(from._internal_data(), _this->GetArenaForAllocation());
  }

  // @@protoc_insertion_point(copy_constructor:FormulaRequest)
}
inline void FormulaRequest::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.formula_){},
      decltype(_impl_.data_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _impl_.formula_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.formula_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.data_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}
FormulaRequest::~FormulaRequest() {
  // @@protoc_insertion_point(destructor:FormulaRequest)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void FormulaRequest::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.formula_.Destroy();
  _impl_.data_.Destroy();
}
void FormulaRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void FormulaRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:FormulaRequest)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.formula_.ClearToEmpty();
  _impl_.data_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* FormulaRequest::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 34, 2> FormulaRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_FormulaRequest_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string data = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(FormulaRequest, _impl_.data_)}},
    // string formula = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(FormulaRequest, _impl_.formula_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string formula = 1;
    {PROTOBUF_FIELD_OFFSET(FormulaRequest, _impl_.formula_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string data = 2;
    {PROTOBUF_FIELD_OFFSET(FormulaRequest, _impl_.data_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\16\7\4\0\0\0\0\0"
    "FormulaRequest"
    "formula"
    "data"
  }},
};

::uint8_t* FormulaRequest::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:FormulaRequest)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string formula = 1;
  if (!this->_internal_formula().empty()) {
    const std::string& _s = this->_internal_formula();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "FormulaRequest.formula");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // string data = 2;
  if (!this->_internal_data().empty()) {
    const std::string& _s = this->_internal_data();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "FormulaRequest.data");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:FormulaRequest)
  return target;
}

::size_t FormulaRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:FormulaRequest)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string formula = 1;
  if (!this->_internal_formula().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_formula());
  }

  // string data = 2;
  if (!this->_internal_data().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_data());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData FormulaRequest::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    FormulaRequest::MergeImpl
};
const ::google::protobuf::Message::ClassData*FormulaRequest::GetClassData() const { return &_class_data_; }


void FormulaRequest::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<FormulaRequest*>(&to_msg);
  auto& from = static_cast<const FormulaRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:FormulaRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_formula().empty()) {
    _this->_internal_set_formula(from._internal_formula());
  }
  if (!from._internal_data().empty()) {
    _this->_internal_set_data(from._internal_data());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void FormulaRequest::CopyFrom(const FormulaRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:FormulaRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool FormulaRequest::IsInitialized() const {
  return true;
}

void FormulaRequest::InternalSwap(FormulaRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.formula_, lhs_arena,
                                       &other->_impl_.formula_, rhs_arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.data_, lhs_arena,
                                       &other->_impl_.data_, rhs_arena);
}

::google::protobuf::Metadata FormulaRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_communication_2eproto_getter, &descriptor_table_communication_2eproto_once,
      file_level_metadata_communication_2eproto[0]);
}
// ===================================================================

class FormulaResponse::_Internal {
 public:
};

FormulaResponse::FormulaResponse(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:FormulaResponse)
}
FormulaResponse::FormulaResponse(const FormulaResponse& from) : ::google::protobuf::Message() {
  FormulaResponse* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.result_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  _impl_.result_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.result_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_result().empty()) {
    _this->_impl_.result_.Set(from._internal_result(), _this->GetArenaForAllocation());
  }

  // @@protoc_insertion_point(copy_constructor:FormulaResponse)
}
inline void FormulaResponse::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.result_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _impl_.result_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.result_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}
FormulaResponse::~FormulaResponse() {
  // @@protoc_insertion_point(destructor:FormulaResponse)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void FormulaResponse::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.result_.Destroy();
}
void FormulaResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void FormulaResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:FormulaResponse)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.result_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* FormulaResponse::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 30, 2> FormulaResponse::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_FormulaResponse_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string result = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(FormulaResponse, _impl_.result_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string result = 1;
    {PROTOBUF_FIELD_OFFSET(FormulaResponse, _impl_.result_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\17\6\0\0\0\0\0\0"
    "FormulaResponse"
    "result"
  }},
};

::uint8_t* FormulaResponse::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:FormulaResponse)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string result = 1;
  if (!this->_internal_result().empty()) {
    const std::string& _s = this->_internal_result();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "FormulaResponse.result");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:FormulaResponse)
  return target;
}

::size_t FormulaResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:FormulaResponse)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string result = 1;
  if (!this->_internal_result().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_result());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData FormulaResponse::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    FormulaResponse::MergeImpl
};
const ::google::protobuf::Message::ClassData*FormulaResponse::GetClassData() const { return &_class_data_; }


void FormulaResponse::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<FormulaResponse*>(&to_msg);
  auto& from = static_cast<const FormulaResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:FormulaResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_result().empty()) {
    _this->_internal_set_result(from._internal_result());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void FormulaResponse::CopyFrom(const FormulaResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:FormulaResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool FormulaResponse::IsInitialized() const {
  return true;
}

void FormulaResponse::InternalSwap(FormulaResponse* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.result_, lhs_arena,
                                       &other->_impl_.result_, rhs_arena);
}

::google::protobuf::Metadata FormulaResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_communication_2eproto_getter, &descriptor_table_communication_2eproto_once,
      file_level_metadata_communication_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
