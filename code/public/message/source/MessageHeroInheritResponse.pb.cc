// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageHeroInheritResponse.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageHeroInheritResponse.pb.h"

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

const ::google::protobuf::Descriptor* HeroInheritResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeroInheritResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageHeroInheritResponse_2eproto() {
  protobuf_AddDesc_MessageHeroInheritResponse_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageHeroInheritResponse.proto");
  GOOGLE_CHECK(file != NULL);
  HeroInheritResponse_descriptor_ = file->message_type(0);
  static const int HeroInheritResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeroInheritResponse, result_),
  };
  HeroInheritResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HeroInheritResponse_descriptor_,
      HeroInheritResponse::default_instance_,
      HeroInheritResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeroInheritResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeroInheritResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HeroInheritResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageHeroInheritResponse_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HeroInheritResponse_descriptor_, &HeroInheritResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageHeroInheritResponse_2eproto() {
  delete HeroInheritResponse::default_instance_;
  delete HeroInheritResponse_reflection_;
}

void protobuf_AddDesc_MessageHeroInheritResponse_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n MessageHeroInheritResponse.proto\022\007Mess"
    "age\"%\n\023HeroInheritResponse\022\016\n\006result\030\001 \001"
    "(\010", 82);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageHeroInheritResponse.proto", &protobuf_RegisterTypes);
  HeroInheritResponse::default_instance_ = new HeroInheritResponse();
  HeroInheritResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageHeroInheritResponse_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageHeroInheritResponse_2eproto {
  StaticDescriptorInitializer_MessageHeroInheritResponse_2eproto() {
    protobuf_AddDesc_MessageHeroInheritResponse_2eproto();
  }
} static_descriptor_initializer_MessageHeroInheritResponse_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HeroInheritResponse::kResultFieldNumber;
#endif  // !_MSC_VER

HeroInheritResponse::HeroInheritResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void HeroInheritResponse::InitAsDefaultInstance() {
}

HeroInheritResponse::HeroInheritResponse(const HeroInheritResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void HeroInheritResponse::SharedCtor() {
  _cached_size_ = 0;
  result_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HeroInheritResponse::~HeroInheritResponse() {
  SharedDtor();
}

void HeroInheritResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void HeroInheritResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeroInheritResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeroInheritResponse_descriptor_;
}

const HeroInheritResponse& HeroInheritResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageHeroInheritResponse_2eproto();
  return *default_instance_;
}

HeroInheritResponse* HeroInheritResponse::default_instance_ = NULL;

HeroInheritResponse* HeroInheritResponse::New() const {
  return new HeroInheritResponse;
}

void HeroInheritResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    result_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HeroInheritResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool result = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &result_)));
          set_has_result();
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

void HeroInheritResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional bool result = 1;
  if (has_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->result(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* HeroInheritResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional bool result = 1;
  if (has_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->result(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int HeroInheritResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool result = 1;
    if (has_result()) {
      total_size += 1 + 1;
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

void HeroInheritResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HeroInheritResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HeroInheritResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HeroInheritResponse::MergeFrom(const HeroInheritResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_result()) {
      set_result(from.result());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HeroInheritResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeroInheritResponse::CopyFrom(const HeroInheritResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeroInheritResponse::IsInitialized() const {

  return true;
}

void HeroInheritResponse::Swap(HeroInheritResponse* other) {
  if (other != this) {
    std::swap(result_, other->result_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HeroInheritResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeroInheritResponse_descriptor_;
  metadata.reflection = HeroInheritResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
