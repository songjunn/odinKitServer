// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageSWChargeChecker.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageSWChargeChecker.pb.h"

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

const ::google::protobuf::Descriptor* SWChargeChecker_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SWChargeChecker_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageSWChargeChecker_2eproto() {
  protobuf_AddDesc_MessageSWChargeChecker_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageSWChargeChecker.proto");
  GOOGLE_CHECK(file != NULL);
  SWChargeChecker_descriptor_ = file->message_type(0);
  static const int SWChargeChecker_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SWChargeChecker, userid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SWChargeChecker, playerid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SWChargeChecker, money_),
  };
  SWChargeChecker_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SWChargeChecker_descriptor_,
      SWChargeChecker::default_instance_,
      SWChargeChecker_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SWChargeChecker, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SWChargeChecker, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SWChargeChecker));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageSWChargeChecker_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SWChargeChecker_descriptor_, &SWChargeChecker::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageSWChargeChecker_2eproto() {
  delete SWChargeChecker::default_instance_;
  delete SWChargeChecker_reflection_;
}

void protobuf_AddDesc_MessageSWChargeChecker_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034MessageSWChargeChecker.proto\022\007Message\""
    "B\n\017SWChargeChecker\022\016\n\006userid\030\001 \001(\003\022\020\n\010pl"
    "ayerid\030\002 \001(\003\022\r\n\005money\030\003 \001(\005", 107);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageSWChargeChecker.proto", &protobuf_RegisterTypes);
  SWChargeChecker::default_instance_ = new SWChargeChecker();
  SWChargeChecker::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageSWChargeChecker_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageSWChargeChecker_2eproto {
  StaticDescriptorInitializer_MessageSWChargeChecker_2eproto() {
    protobuf_AddDesc_MessageSWChargeChecker_2eproto();
  }
} static_descriptor_initializer_MessageSWChargeChecker_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SWChargeChecker::kUseridFieldNumber;
const int SWChargeChecker::kPlayeridFieldNumber;
const int SWChargeChecker::kMoneyFieldNumber;
#endif  // !_MSC_VER

SWChargeChecker::SWChargeChecker()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SWChargeChecker::InitAsDefaultInstance() {
}

SWChargeChecker::SWChargeChecker(const SWChargeChecker& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SWChargeChecker::SharedCtor() {
  _cached_size_ = 0;
  userid_ = GOOGLE_LONGLONG(0);
  playerid_ = GOOGLE_LONGLONG(0);
  money_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SWChargeChecker::~SWChargeChecker() {
  SharedDtor();
}

void SWChargeChecker::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SWChargeChecker::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SWChargeChecker::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SWChargeChecker_descriptor_;
}

const SWChargeChecker& SWChargeChecker::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageSWChargeChecker_2eproto();
  return *default_instance_;
}

SWChargeChecker* SWChargeChecker::default_instance_ = NULL;

SWChargeChecker* SWChargeChecker::New() const {
  return new SWChargeChecker;
}

void SWChargeChecker::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    userid_ = GOOGLE_LONGLONG(0);
    playerid_ = GOOGLE_LONGLONG(0);
    money_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SWChargeChecker::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 userid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &userid_)));
          set_has_userid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_playerid;
        break;
      }

      // optional int64 playerid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_playerid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &playerid_)));
          set_has_playerid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_money;
        break;
      }

      // optional int32 money = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_money:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &money_)));
          set_has_money();
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

void SWChargeChecker::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 userid = 1;
  if (has_userid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->userid(), output);
  }

  // optional int64 playerid = 2;
  if (has_playerid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->playerid(), output);
  }

  // optional int32 money = 3;
  if (has_money()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->money(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SWChargeChecker::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 userid = 1;
  if (has_userid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->userid(), target);
  }

  // optional int64 playerid = 2;
  if (has_playerid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->playerid(), target);
  }

  // optional int32 money = 3;
  if (has_money()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->money(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SWChargeChecker::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 userid = 1;
    if (has_userid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->userid());
    }

    // optional int64 playerid = 2;
    if (has_playerid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->playerid());
    }

    // optional int32 money = 3;
    if (has_money()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->money());
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

void SWChargeChecker::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SWChargeChecker* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SWChargeChecker*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SWChargeChecker::MergeFrom(const SWChargeChecker& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_userid()) {
      set_userid(from.userid());
    }
    if (from.has_playerid()) {
      set_playerid(from.playerid());
    }
    if (from.has_money()) {
      set_money(from.money());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SWChargeChecker::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SWChargeChecker::CopyFrom(const SWChargeChecker& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SWChargeChecker::IsInitialized() const {

  return true;
}

void SWChargeChecker::Swap(SWChargeChecker* other) {
  if (other != this) {
    std::swap(userid_, other->userid_);
    std::swap(playerid_, other->playerid_);
    std::swap(money_, other->money_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SWChargeChecker::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SWChargeChecker_descriptor_;
  metadata.reflection = SWChargeChecker_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
