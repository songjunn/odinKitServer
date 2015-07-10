// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageFormatInfoNotify.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageFormatInfoNotify.pb.h"

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

const ::google::protobuf::Descriptor* FormatInfoNotify_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FormatInfoNotify_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageFormatInfoNotify_2eproto() {
  protobuf_AddDesc_MessageFormatInfoNotify_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageFormatInfoNotify.proto");
  GOOGLE_CHECK(file != NULL);
  FormatInfoNotify_descriptor_ = file->message_type(0);
  static const int FormatInfoNotify_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatInfoNotify, format_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatInfoNotify, level_),
  };
  FormatInfoNotify_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FormatInfoNotify_descriptor_,
      FormatInfoNotify::default_instance_,
      FormatInfoNotify_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatInfoNotify, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatInfoNotify, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FormatInfoNotify));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageFormatInfoNotify_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FormatInfoNotify_descriptor_, &FormatInfoNotify::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageFormatInfoNotify_2eproto() {
  delete FormatInfoNotify::default_instance_;
  delete FormatInfoNotify_reflection_;
}

void protobuf_AddDesc_MessageFormatInfoNotify_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\035MessageFormatInfoNotify.proto\022\007Message"
    "\"1\n\020FormatInfoNotify\022\016\n\006format\030\001 \001(\005\022\r\n\005"
    "level\030\002 \001(\005", 91);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageFormatInfoNotify.proto", &protobuf_RegisterTypes);
  FormatInfoNotify::default_instance_ = new FormatInfoNotify();
  FormatInfoNotify::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageFormatInfoNotify_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageFormatInfoNotify_2eproto {
  StaticDescriptorInitializer_MessageFormatInfoNotify_2eproto() {
    protobuf_AddDesc_MessageFormatInfoNotify_2eproto();
  }
} static_descriptor_initializer_MessageFormatInfoNotify_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int FormatInfoNotify::kFormatFieldNumber;
const int FormatInfoNotify::kLevelFieldNumber;
#endif  // !_MSC_VER

FormatInfoNotify::FormatInfoNotify()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void FormatInfoNotify::InitAsDefaultInstance() {
}

FormatInfoNotify::FormatInfoNotify(const FormatInfoNotify& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void FormatInfoNotify::SharedCtor() {
  _cached_size_ = 0;
  format_ = 0;
  level_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FormatInfoNotify::~FormatInfoNotify() {
  SharedDtor();
}

void FormatInfoNotify::SharedDtor() {
  if (this != default_instance_) {
  }
}

void FormatInfoNotify::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FormatInfoNotify::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FormatInfoNotify_descriptor_;
}

const FormatInfoNotify& FormatInfoNotify::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFormatInfoNotify_2eproto();
  return *default_instance_;
}

FormatInfoNotify* FormatInfoNotify::default_instance_ = NULL;

FormatInfoNotify* FormatInfoNotify::New() const {
  return new FormatInfoNotify;
}

void FormatInfoNotify::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    format_ = 0;
    level_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FormatInfoNotify::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 format = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &format_)));
          set_has_format();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_level;
        break;
      }

      // optional int32 level = 2;
      case 2: {
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

void FormatInfoNotify::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 format = 1;
  if (has_format()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->format(), output);
  }

  // optional int32 level = 2;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->level(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* FormatInfoNotify::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 format = 1;
  if (has_format()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->format(), target);
  }

  // optional int32 level = 2;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->level(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int FormatInfoNotify::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 format = 1;
    if (has_format()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->format());
    }

    // optional int32 level = 2;
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->level());
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

void FormatInfoNotify::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FormatInfoNotify* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FormatInfoNotify*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FormatInfoNotify::MergeFrom(const FormatInfoNotify& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_format()) {
      set_format(from.format());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FormatInfoNotify::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FormatInfoNotify::CopyFrom(const FormatInfoNotify& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FormatInfoNotify::IsInitialized() const {

  return true;
}

void FormatInfoNotify::Swap(FormatInfoNotify* other) {
  if (other != this) {
    std::swap(format_, other->format_);
    std::swap(level_, other->level_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FormatInfoNotify::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FormatInfoNotify_descriptor_;
  metadata.reflection = FormatInfoNotify_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
