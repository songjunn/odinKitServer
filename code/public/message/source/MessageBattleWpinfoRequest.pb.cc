// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageBattleWpinfoRequest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageBattleWpinfoRequest.pb.h"

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

const ::google::protobuf::Descriptor* BattleWpinfoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BattleWpinfoRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageBattleWpinfoRequest_2eproto() {
  protobuf_AddDesc_MessageBattleWpinfoRequest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageBattleWpinfoRequest.proto");
  GOOGLE_CHECK(file != NULL);
  BattleWpinfoRequest_descriptor_ = file->message_type(0);
  static const int BattleWpinfoRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BattleWpinfoRequest, pid_),
  };
  BattleWpinfoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BattleWpinfoRequest_descriptor_,
      BattleWpinfoRequest::default_instance_,
      BattleWpinfoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BattleWpinfoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BattleWpinfoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BattleWpinfoRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageBattleWpinfoRequest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BattleWpinfoRequest_descriptor_, &BattleWpinfoRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageBattleWpinfoRequest_2eproto() {
  delete BattleWpinfoRequest::default_instance_;
  delete BattleWpinfoRequest_reflection_;
}

void protobuf_AddDesc_MessageBattleWpinfoRequest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n MessageBattleWpinfoRequest.proto\022\007Mess"
    "age\"\"\n\023BattleWpinfoRequest\022\013\n\003pid\030\001 \001(\003", 79);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageBattleWpinfoRequest.proto", &protobuf_RegisterTypes);
  BattleWpinfoRequest::default_instance_ = new BattleWpinfoRequest();
  BattleWpinfoRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageBattleWpinfoRequest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageBattleWpinfoRequest_2eproto {
  StaticDescriptorInitializer_MessageBattleWpinfoRequest_2eproto() {
    protobuf_AddDesc_MessageBattleWpinfoRequest_2eproto();
  }
} static_descriptor_initializer_MessageBattleWpinfoRequest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int BattleWpinfoRequest::kPidFieldNumber;
#endif  // !_MSC_VER

BattleWpinfoRequest::BattleWpinfoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void BattleWpinfoRequest::InitAsDefaultInstance() {
}

BattleWpinfoRequest::BattleWpinfoRequest(const BattleWpinfoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void BattleWpinfoRequest::SharedCtor() {
  _cached_size_ = 0;
  pid_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BattleWpinfoRequest::~BattleWpinfoRequest() {
  SharedDtor();
}

void BattleWpinfoRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BattleWpinfoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BattleWpinfoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BattleWpinfoRequest_descriptor_;
}

const BattleWpinfoRequest& BattleWpinfoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageBattleWpinfoRequest_2eproto();
  return *default_instance_;
}

BattleWpinfoRequest* BattleWpinfoRequest::default_instance_ = NULL;

BattleWpinfoRequest* BattleWpinfoRequest::New() const {
  return new BattleWpinfoRequest;
}

void BattleWpinfoRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pid_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BattleWpinfoRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 pid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &pid_)));
          set_has_pid();
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

void BattleWpinfoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->pid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* BattleWpinfoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->pid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int BattleWpinfoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 pid = 1;
    if (has_pid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->pid());
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

void BattleWpinfoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BattleWpinfoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BattleWpinfoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BattleWpinfoRequest::MergeFrom(const BattleWpinfoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pid()) {
      set_pid(from.pid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BattleWpinfoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BattleWpinfoRequest::CopyFrom(const BattleWpinfoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BattleWpinfoRequest::IsInitialized() const {

  return true;
}

void BattleWpinfoRequest::Swap(BattleWpinfoRequest* other) {
  if (other != this) {
    std::swap(pid_, other->pid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BattleWpinfoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BattleWpinfoRequest_descriptor_;
  metadata.reflection = BattleWpinfoRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
