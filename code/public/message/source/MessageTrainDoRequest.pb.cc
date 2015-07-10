// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageTrainDoRequest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageTrainDoRequest.pb.h"

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

const ::google::protobuf::Descriptor* TrainDoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TrainDoRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageTrainDoRequest_2eproto() {
  protobuf_AddDesc_MessageTrainDoRequest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageTrainDoRequest.proto");
  GOOGLE_CHECK(file != NULL);
  TrainDoRequest_descriptor_ = file->message_type(0);
  static const int TrainDoRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TrainDoRequest, role_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TrainDoRequest, type_),
  };
  TrainDoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      TrainDoRequest_descriptor_,
      TrainDoRequest::default_instance_,
      TrainDoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TrainDoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TrainDoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(TrainDoRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageTrainDoRequest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    TrainDoRequest_descriptor_, &TrainDoRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageTrainDoRequest_2eproto() {
  delete TrainDoRequest::default_instance_;
  delete TrainDoRequest_reflection_;
}

void protobuf_AddDesc_MessageTrainDoRequest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\033MessageTrainDoRequest.proto\022\007Message\","
    "\n\016TrainDoRequest\022\014\n\004role\030\001 \001(\003\022\014\n\004type\030\002"
    " \001(\005", 84);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageTrainDoRequest.proto", &protobuf_RegisterTypes);
  TrainDoRequest::default_instance_ = new TrainDoRequest();
  TrainDoRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageTrainDoRequest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageTrainDoRequest_2eproto {
  StaticDescriptorInitializer_MessageTrainDoRequest_2eproto() {
    protobuf_AddDesc_MessageTrainDoRequest_2eproto();
  }
} static_descriptor_initializer_MessageTrainDoRequest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int TrainDoRequest::kRoleFieldNumber;
const int TrainDoRequest::kTypeFieldNumber;
#endif  // !_MSC_VER

TrainDoRequest::TrainDoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void TrainDoRequest::InitAsDefaultInstance() {
}

TrainDoRequest::TrainDoRequest(const TrainDoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void TrainDoRequest::SharedCtor() {
  _cached_size_ = 0;
  role_ = GOOGLE_LONGLONG(0);
  type_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

TrainDoRequest::~TrainDoRequest() {
  SharedDtor();
}

void TrainDoRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void TrainDoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TrainDoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TrainDoRequest_descriptor_;
}

const TrainDoRequest& TrainDoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageTrainDoRequest_2eproto();
  return *default_instance_;
}

TrainDoRequest* TrainDoRequest::default_instance_ = NULL;

TrainDoRequest* TrainDoRequest::New() const {
  return new TrainDoRequest;
}

void TrainDoRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    role_ = GOOGLE_LONGLONG(0);
    type_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool TrainDoRequest::MergePartialFromCodedStream(
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
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }

      // optional int32 type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));
          set_has_type();
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

void TrainDoRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 role = 1;
  if (has_role()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->role(), output);
  }

  // optional int32 type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* TrainDoRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 role = 1;
  if (has_role()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->role(), target);
  }

  // optional int32 type = 2;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int TrainDoRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 role = 1;
    if (has_role()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->role());
    }

    // optional int32 type = 2;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->type());
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

void TrainDoRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const TrainDoRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const TrainDoRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void TrainDoRequest::MergeFrom(const TrainDoRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_role()) {
      set_role(from.role());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void TrainDoRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TrainDoRequest::CopyFrom(const TrainDoRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TrainDoRequest::IsInitialized() const {

  return true;
}

void TrainDoRequest::Swap(TrainDoRequest* other) {
  if (other != this) {
    std::swap(role_, other->role_);
    std::swap(type_, other->type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata TrainDoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TrainDoRequest_descriptor_;
  metadata.reflection = TrainDoRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
