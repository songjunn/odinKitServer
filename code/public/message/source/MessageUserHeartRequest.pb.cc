// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageUserHeartRequest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageUserHeartRequest.pb.h"

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

const ::google::protobuf::Descriptor* UserHeartRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UserHeartRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageUserHeartRequest_2eproto() {
  protobuf_AddDesc_MessageUserHeartRequest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageUserHeartRequest.proto");
  GOOGLE_CHECK(file != NULL);
  UserHeartRequest_descriptor_ = file->message_type(0);
  static const int UserHeartRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserHeartRequest, pid_),
  };
  UserHeartRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UserHeartRequest_descriptor_,
      UserHeartRequest::default_instance_,
      UserHeartRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserHeartRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserHeartRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UserHeartRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageUserHeartRequest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UserHeartRequest_descriptor_, &UserHeartRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageUserHeartRequest_2eproto() {
  delete UserHeartRequest::default_instance_;
  delete UserHeartRequest_reflection_;
}

void protobuf_AddDesc_MessageUserHeartRequest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\035MessageUserHeartRequest.proto\022\007Message"
    "\"\037\n\020UserHeartRequest\022\013\n\003pid\030\001 \001(\003", 73);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageUserHeartRequest.proto", &protobuf_RegisterTypes);
  UserHeartRequest::default_instance_ = new UserHeartRequest();
  UserHeartRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageUserHeartRequest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageUserHeartRequest_2eproto {
  StaticDescriptorInitializer_MessageUserHeartRequest_2eproto() {
    protobuf_AddDesc_MessageUserHeartRequest_2eproto();
  }
} static_descriptor_initializer_MessageUserHeartRequest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int UserHeartRequest::kPidFieldNumber;
#endif  // !_MSC_VER

UserHeartRequest::UserHeartRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void UserHeartRequest::InitAsDefaultInstance() {
}

UserHeartRequest::UserHeartRequest(const UserHeartRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void UserHeartRequest::SharedCtor() {
  _cached_size_ = 0;
  pid_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UserHeartRequest::~UserHeartRequest() {
  SharedDtor();
}

void UserHeartRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void UserHeartRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UserHeartRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserHeartRequest_descriptor_;
}

const UserHeartRequest& UserHeartRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageUserHeartRequest_2eproto();
  return *default_instance_;
}

UserHeartRequest* UserHeartRequest::default_instance_ = NULL;

UserHeartRequest* UserHeartRequest::New() const {
  return new UserHeartRequest;
}

void UserHeartRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pid_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UserHeartRequest::MergePartialFromCodedStream(
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

void UserHeartRequest::SerializeWithCachedSizes(
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

::google::protobuf::uint8* UserHeartRequest::SerializeWithCachedSizesToArray(
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

int UserHeartRequest::ByteSize() const {
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

void UserHeartRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UserHeartRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UserHeartRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UserHeartRequest::MergeFrom(const UserHeartRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pid()) {
      set_pid(from.pid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UserHeartRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserHeartRequest::CopyFrom(const UserHeartRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserHeartRequest::IsInitialized() const {

  return true;
}

void UserHeartRequest::Swap(UserHeartRequest* other) {
  if (other != this) {
    std::swap(pid_, other->pid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UserHeartRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UserHeartRequest_descriptor_;
  metadata.reflection = UserHeartRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
