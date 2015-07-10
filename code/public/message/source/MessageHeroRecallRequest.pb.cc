// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageHeroRecallRequest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageHeroRecallRequest.pb.h"

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

const ::google::protobuf::Descriptor* HeroRecallRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeroRecallRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageHeroRecallRequest_2eproto() {
  protobuf_AddDesc_MessageHeroRecallRequest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageHeroRecallRequest.proto");
  GOOGLE_CHECK(file != NULL);
  HeroRecallRequest_descriptor_ = file->message_type(0);
  static const int HeroRecallRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeroRecallRequest, hero_),
  };
  HeroRecallRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HeroRecallRequest_descriptor_,
      HeroRecallRequest::default_instance_,
      HeroRecallRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeroRecallRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeroRecallRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HeroRecallRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageHeroRecallRequest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HeroRecallRequest_descriptor_, &HeroRecallRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageHeroRecallRequest_2eproto() {
  delete HeroRecallRequest::default_instance_;
  delete HeroRecallRequest_reflection_;
}

void protobuf_AddDesc_MessageHeroRecallRequest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\036MessageHeroRecallRequest.proto\022\007Messag"
    "e\"!\n\021HeroRecallRequest\022\014\n\004hero\030\001 \001(\003", 76);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageHeroRecallRequest.proto", &protobuf_RegisterTypes);
  HeroRecallRequest::default_instance_ = new HeroRecallRequest();
  HeroRecallRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageHeroRecallRequest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageHeroRecallRequest_2eproto {
  StaticDescriptorInitializer_MessageHeroRecallRequest_2eproto() {
    protobuf_AddDesc_MessageHeroRecallRequest_2eproto();
  }
} static_descriptor_initializer_MessageHeroRecallRequest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HeroRecallRequest::kHeroFieldNumber;
#endif  // !_MSC_VER

HeroRecallRequest::HeroRecallRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void HeroRecallRequest::InitAsDefaultInstance() {
}

HeroRecallRequest::HeroRecallRequest(const HeroRecallRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void HeroRecallRequest::SharedCtor() {
  _cached_size_ = 0;
  hero_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HeroRecallRequest::~HeroRecallRequest() {
  SharedDtor();
}

void HeroRecallRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void HeroRecallRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeroRecallRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeroRecallRequest_descriptor_;
}

const HeroRecallRequest& HeroRecallRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageHeroRecallRequest_2eproto();
  return *default_instance_;
}

HeroRecallRequest* HeroRecallRequest::default_instance_ = NULL;

HeroRecallRequest* HeroRecallRequest::New() const {
  return new HeroRecallRequest;
}

void HeroRecallRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    hero_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HeroRecallRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 hero = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &hero_)));
          set_has_hero();
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

void HeroRecallRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 hero = 1;
  if (has_hero()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->hero(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* HeroRecallRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 hero = 1;
  if (has_hero()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->hero(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int HeroRecallRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 hero = 1;
    if (has_hero()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->hero());
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

void HeroRecallRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HeroRecallRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HeroRecallRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HeroRecallRequest::MergeFrom(const HeroRecallRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_hero()) {
      set_hero(from.hero());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HeroRecallRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeroRecallRequest::CopyFrom(const HeroRecallRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeroRecallRequest::IsInitialized() const {

  return true;
}

void HeroRecallRequest::Swap(HeroRecallRequest* other) {
  if (other != this) {
    std::swap(hero_, other->hero_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HeroRecallRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeroRecallRequest_descriptor_;
  metadata.reflection = HeroRecallRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
