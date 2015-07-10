// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageStarsInfo.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageStarsInfo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Message {

namespace {

const ::google::protobuf::Descriptor* StarsInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  StarsInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* StarsInfo_Star_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  StarsInfo_Star_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageStarsInfo_2eproto() {
  protobuf_AddDesc_MessageStarsInfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageStarsInfo.proto");
  GOOGLE_CHECK(file != NULL);
  StarsInfo_descriptor_ = file->message_type(0);
  static const int StarsInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo, star_),
  };
  StarsInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      StarsInfo_descriptor_,
      StarsInfo::default_instance_,
      StarsInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(StarsInfo));
  StarsInfo_Star_descriptor_ = StarsInfo_descriptor_->nested_type(0);
  static const int StarsInfo_Star_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo_Star, idx_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo_Star, active_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo_Star, level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo_Star, item_),
  };
  StarsInfo_Star_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      StarsInfo_Star_descriptor_,
      StarsInfo_Star::default_instance_,
      StarsInfo_Star_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo_Star, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StarsInfo_Star, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(StarsInfo_Star));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageStarsInfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    StarsInfo_descriptor_, &StarsInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    StarsInfo_Star_descriptor_, &StarsInfo_Star::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageStarsInfo_2eproto() {
  delete StarsInfo::default_instance_;
  delete StarsInfo_reflection_;
  delete StarsInfo_Star::default_instance_;
  delete StarsInfo_Star_reflection_;
}

void protobuf_AddDesc_MessageStarsInfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026MessageStarsInfo.proto\022\007Message\"\202\001\n\tSt"
    "arsInfo\022\014\n\004role\030\001 \001(\003\022%\n\004star\030\002 \003(\0132\027.Me"
    "ssage.StarsInfo.Star\032@\n\004Star\022\013\n\003idx\030\001 \001("
    "\005\022\016\n\006active\030\002 \001(\005\022\r\n\005level\030\003 \001(\005\022\014\n\004item"
    "\030\004 \001(\005", 166);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageStarsInfo.proto", &protobuf_RegisterTypes);
  StarsInfo::default_instance_ = new StarsInfo();
  StarsInfo_Star::default_instance_ = new StarsInfo_Star();
  StarsInfo::default_instance_->InitAsDefaultInstance();
  StarsInfo_Star::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageStarsInfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageStarsInfo_2eproto {
  StaticDescriptorInitializer_MessageStarsInfo_2eproto() {
    protobuf_AddDesc_MessageStarsInfo_2eproto();
  }
} static_descriptor_initializer_MessageStarsInfo_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int StarsInfo_Star::kIdxFieldNumber;
const int StarsInfo_Star::kActiveFieldNumber;
const int StarsInfo_Star::kLevelFieldNumber;
const int StarsInfo_Star::kItemFieldNumber;
#endif  // !_MSC_VER

StarsInfo_Star::StarsInfo_Star()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void StarsInfo_Star::InitAsDefaultInstance() {
}

StarsInfo_Star::StarsInfo_Star(const StarsInfo_Star& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void StarsInfo_Star::SharedCtor() {
  _cached_size_ = 0;
  idx_ = 0;
  active_ = 0;
  level_ = 0;
  item_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

StarsInfo_Star::~StarsInfo_Star() {
  SharedDtor();
}

void StarsInfo_Star::SharedDtor() {
  if (this != default_instance_) {
  }
}

void StarsInfo_Star::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StarsInfo_Star::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StarsInfo_Star_descriptor_;
}

const StarsInfo_Star& StarsInfo_Star::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageStarsInfo_2eproto();
  return *default_instance_;
}

StarsInfo_Star* StarsInfo_Star::default_instance_ = NULL;

StarsInfo_Star* StarsInfo_Star::New() const {
  return new StarsInfo_Star;
}

void StarsInfo_Star::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    idx_ = 0;
    active_ = 0;
    level_ = 0;
    item_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool StarsInfo_Star::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 idx = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &idx_)));
          set_has_idx();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_active;
        break;
      }

      // optional int32 active = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_active:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &active_)));
          set_has_active();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_level;
        break;
      }

      // optional int32 level = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_level:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &level_)));
          set_has_level();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_item;
        break;
      }

      // optional int32 item = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_item:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &item_)));
          set_has_item();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void StarsInfo_Star::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 idx = 1;
  if (has_idx()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->idx(), output);
  }

  // optional int32 active = 2;
  if (has_active()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->active(), output);
  }

  // optional int32 level = 3;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->level(), output);
  }

  // optional int32 item = 4;
  if (has_item()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->item(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* StarsInfo_Star::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 idx = 1;
  if (has_idx()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->idx(), target);
  }

  // optional int32 active = 2;
  if (has_active()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->active(), target);
  }

  // optional int32 level = 3;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->level(), target);
  }

  // optional int32 item = 4;
  if (has_item()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->item(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int StarsInfo_Star::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 idx = 1;
    if (has_idx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->idx());
    }

    // optional int32 active = 2;
    if (has_active()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->active());
    }

    // optional int32 level = 3;
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->level());
    }

    // optional int32 item = 4;
    if (has_item()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->item());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StarsInfo_Star::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const StarsInfo_Star* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const StarsInfo_Star*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void StarsInfo_Star::MergeFrom(const StarsInfo_Star& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_idx()) {
      set_idx(from.idx());
    }
    if (from.has_active()) {
      set_active(from.active());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
    if (from.has_item()) {
      set_item(from.item());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void StarsInfo_Star::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StarsInfo_Star::CopyFrom(const StarsInfo_Star& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StarsInfo_Star::IsInitialized() const {

  return true;
}

void StarsInfo_Star::Swap(StarsInfo_Star* other) {
  if (other != this) {
    std::swap(idx_, other->idx_);
    std::swap(active_, other->active_);
    std::swap(level_, other->level_);
    std::swap(item_, other->item_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata StarsInfo_Star::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = StarsInfo_Star_descriptor_;
  metadata.reflection = StarsInfo_Star_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int StarsInfo::kRoleFieldNumber;
const int StarsInfo::kStarFieldNumber;
#endif  // !_MSC_VER

StarsInfo::StarsInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void StarsInfo::InitAsDefaultInstance() {
}

StarsInfo::StarsInfo(const StarsInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void StarsInfo::SharedCtor() {
  _cached_size_ = 0;
  role_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

StarsInfo::~StarsInfo() {
  SharedDtor();
}

void StarsInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void StarsInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StarsInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StarsInfo_descriptor_;
}

const StarsInfo& StarsInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageStarsInfo_2eproto();
  return *default_instance_;
}

StarsInfo* StarsInfo::default_instance_ = NULL;

StarsInfo* StarsInfo::New() const {
  return new StarsInfo;
}

void StarsInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    role_ = GOOGLE_LONGLONG(0);
  }
  star_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool StarsInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 role = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &role_)));
          set_has_role();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_star;
        break;
      }

      // repeated .Message.StarsInfo.Star star = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_star:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_star()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_star;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void StarsInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 role = 1;
  if (has_role()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->role(), output);
  }

  // repeated .Message.StarsInfo.Star star = 2;
  for (int i = 0; i < this->star_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->star(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* StarsInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 role = 1;
  if (has_role()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->role(), target);
  }

  // repeated .Message.StarsInfo.Star star = 2;
  for (int i = 0; i < this->star_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->star(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int StarsInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 role = 1;
    if (has_role()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->role());
    }

  }
  // repeated .Message.StarsInfo.Star star = 2;
  total_size += 1 * this->star_size();
  for (int i = 0; i < this->star_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->star(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StarsInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const StarsInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const StarsInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void StarsInfo::MergeFrom(const StarsInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  star_.MergeFrom(from.star_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_role()) {
      set_role(from.role());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void StarsInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StarsInfo::CopyFrom(const StarsInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StarsInfo::IsInitialized() const {

  return true;
}

void StarsInfo::Swap(StarsInfo* other) {
  if (other != this) {
    std::swap(role_, other->role_);
    star_.Swap(&other->star_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata StarsInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = StarsInfo_descriptor_;
  metadata.reflection = StarsInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
