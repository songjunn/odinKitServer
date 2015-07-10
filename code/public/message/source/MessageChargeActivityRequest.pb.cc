// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageChargeActivityRequest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageChargeActivityRequest.pb.h"

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

const ::google::protobuf::Descriptor* ChargeActivityRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ChargeActivityRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageChargeActivityRequest_2eproto() {
  protobuf_AddDesc_MessageChargeActivityRequest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageChargeActivityRequest.proto");
  GOOGLE_CHECK(file != NULL);
  ChargeActivityRequest_descriptor_ = file->message_type(0);
  static const int ChargeActivityRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChargeActivityRequest, playerid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChargeActivityRequest, idx_),
  };
  ChargeActivityRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ChargeActivityRequest_descriptor_,
      ChargeActivityRequest::default_instance_,
      ChargeActivityRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChargeActivityRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ChargeActivityRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ChargeActivityRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageChargeActivityRequest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ChargeActivityRequest_descriptor_, &ChargeActivityRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageChargeActivityRequest_2eproto() {
  delete ChargeActivityRequest::default_instance_;
  delete ChargeActivityRequest_reflection_;
}

void protobuf_AddDesc_MessageChargeActivityRequest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\"MessageChargeActivityRequest.proto\022\007Me"
    "ssage\"6\n\025ChargeActivityRequest\022\020\n\010player"
    "id\030\001 \001(\003\022\013\n\003idx\030\002 \001(\005", 101);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageChargeActivityRequest.proto", &protobuf_RegisterTypes);
  ChargeActivityRequest::default_instance_ = new ChargeActivityRequest();
  ChargeActivityRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageChargeActivityRequest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageChargeActivityRequest_2eproto {
  StaticDescriptorInitializer_MessageChargeActivityRequest_2eproto() {
    protobuf_AddDesc_MessageChargeActivityRequest_2eproto();
  }
} static_descriptor_initializer_MessageChargeActivityRequest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ChargeActivityRequest::kPlayeridFieldNumber;
const int ChargeActivityRequest::kIdxFieldNumber;
#endif  // !_MSC_VER

ChargeActivityRequest::ChargeActivityRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ChargeActivityRequest::InitAsDefaultInstance() {
}

ChargeActivityRequest::ChargeActivityRequest(const ChargeActivityRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ChargeActivityRequest::SharedCtor() {
  _cached_size_ = 0;
  playerid_ = GOOGLE_LONGLONG(0);
  idx_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ChargeActivityRequest::~ChargeActivityRequest() {
  SharedDtor();
}

void ChargeActivityRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ChargeActivityRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChargeActivityRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ChargeActivityRequest_descriptor_;
}

const ChargeActivityRequest& ChargeActivityRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageChargeActivityRequest_2eproto();
  return *default_instance_;
}

ChargeActivityRequest* ChargeActivityRequest::default_instance_ = NULL;

ChargeActivityRequest* ChargeActivityRequest::New() const {
  return new ChargeActivityRequest;
}

void ChargeActivityRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    playerid_ = GOOGLE_LONGLONG(0);
    idx_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ChargeActivityRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 playerid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &playerid_)));
          set_has_playerid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_idx;
        break;
      }

      // optional int32 idx = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_idx:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &idx_)));
          set_has_idx();
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

void ChargeActivityRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 playerid = 1;
  if (has_playerid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->playerid(), output);
  }

  // optional int32 idx = 2;
  if (has_idx()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->idx(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ChargeActivityRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 playerid = 1;
  if (has_playerid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->playerid(), target);
  }

  // optional int32 idx = 2;
  if (has_idx()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->idx(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ChargeActivityRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 playerid = 1;
    if (has_playerid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->playerid());
    }

    // optional int32 idx = 2;
    if (has_idx()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->idx());
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

void ChargeActivityRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ChargeActivityRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ChargeActivityRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ChargeActivityRequest::MergeFrom(const ChargeActivityRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_playerid()) {
      set_playerid(from.playerid());
    }
    if (from.has_idx()) {
      set_idx(from.idx());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ChargeActivityRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChargeActivityRequest::CopyFrom(const ChargeActivityRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChargeActivityRequest::IsInitialized() const {

  return true;
}

void ChargeActivityRequest::Swap(ChargeActivityRequest* other) {
  if (other != this) {
    std::swap(playerid_, other->playerid_);
    std::swap(idx_, other->idx_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ChargeActivityRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ChargeActivityRequest_descriptor_;
  metadata.reflection = ChargeActivityRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
