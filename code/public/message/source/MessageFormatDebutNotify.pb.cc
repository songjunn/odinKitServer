// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageFormatDebutNotify.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageFormatDebutNotify.pb.h"

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

const ::google::protobuf::Descriptor* FormatDebutNotify_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FormatDebutNotify_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageFormatDebutNotify_2eproto() {
  protobuf_AddDesc_MessageFormatDebutNotify_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageFormatDebutNotify.proto");
  GOOGLE_CHECK(file != NULL);
  FormatDebutNotify_descriptor_ = file->message_type(0);
  static const int FormatDebutNotify_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatDebutNotify, playerid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatDebutNotify, format_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatDebutNotify, fighter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatDebutNotify, helperpos_),
  };
  FormatDebutNotify_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FormatDebutNotify_descriptor_,
      FormatDebutNotify::default_instance_,
      FormatDebutNotify_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatDebutNotify, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FormatDebutNotify, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FormatDebutNotify));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageFormatDebutNotify_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FormatDebutNotify_descriptor_, &FormatDebutNotify::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageFormatDebutNotify_2eproto() {
  delete FormatDebutNotify::default_instance_;
  delete FormatDebutNotify_reflection_;
}

void protobuf_AddDesc_MessageFormatDebutNotify_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\036MessageFormatDebutNotify.proto\022\007Messag"
    "e\"Y\n\021FormatDebutNotify\022\020\n\010playerid\030\001 \001(\003"
    "\022\016\n\006format\030\002 \001(\005\022\017\n\007fighter\030\003 \003(\003\022\021\n\thel"
    "perpos\030\004 \001(\005", 132);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageFormatDebutNotify.proto", &protobuf_RegisterTypes);
  FormatDebutNotify::default_instance_ = new FormatDebutNotify();
  FormatDebutNotify::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageFormatDebutNotify_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageFormatDebutNotify_2eproto {
  StaticDescriptorInitializer_MessageFormatDebutNotify_2eproto() {
    protobuf_AddDesc_MessageFormatDebutNotify_2eproto();
  }
} static_descriptor_initializer_MessageFormatDebutNotify_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int FormatDebutNotify::kPlayeridFieldNumber;
const int FormatDebutNotify::kFormatFieldNumber;
const int FormatDebutNotify::kFighterFieldNumber;
const int FormatDebutNotify::kHelperposFieldNumber;
#endif  // !_MSC_VER

FormatDebutNotify::FormatDebutNotify()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void FormatDebutNotify::InitAsDefaultInstance() {
}

FormatDebutNotify::FormatDebutNotify(const FormatDebutNotify& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void FormatDebutNotify::SharedCtor() {
  _cached_size_ = 0;
  playerid_ = GOOGLE_LONGLONG(0);
  format_ = 0;
  helperpos_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FormatDebutNotify::~FormatDebutNotify() {
  SharedDtor();
}

void FormatDebutNotify::SharedDtor() {
  if (this != default_instance_) {
  }
}

void FormatDebutNotify::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FormatDebutNotify::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FormatDebutNotify_descriptor_;
}

const FormatDebutNotify& FormatDebutNotify::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFormatDebutNotify_2eproto();
  return *default_instance_;
}

FormatDebutNotify* FormatDebutNotify::default_instance_ = NULL;

FormatDebutNotify* FormatDebutNotify::New() const {
  return new FormatDebutNotify;
}

void FormatDebutNotify::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    playerid_ = GOOGLE_LONGLONG(0);
    format_ = 0;
    helperpos_ = 0;
  }
  fighter_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FormatDebutNotify::MergePartialFromCodedStream(
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
        if (input->ExpectTag(16)) goto parse_format;
        break;
      }

      // optional int32 format = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_format:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &format_)));
          set_has_format();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_fighter;
        break;
      }

      // repeated int64 fighter = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fighter:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 24, input, this->mutable_fighter())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_fighter())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_fighter;
        if (input->ExpectTag(32)) goto parse_helperpos;
        break;
      }

      // optional int32 helperpos = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_helperpos:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &helperpos_)));
          set_has_helperpos();
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

void FormatDebutNotify::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 playerid = 1;
  if (has_playerid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->playerid(), output);
  }

  // optional int32 format = 2;
  if (has_format()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->format(), output);
  }

  // repeated int64 fighter = 3;
  for (int i = 0; i < this->fighter_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      3, this->fighter(i), output);
  }

  // optional int32 helperpos = 4;
  if (has_helperpos()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->helperpos(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* FormatDebutNotify::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 playerid = 1;
  if (has_playerid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->playerid(), target);
  }

  // optional int32 format = 2;
  if (has_format()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->format(), target);
  }

  // repeated int64 fighter = 3;
  for (int i = 0; i < this->fighter_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(3, this->fighter(i), target);
  }

  // optional int32 helperpos = 4;
  if (has_helperpos()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->helperpos(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int FormatDebutNotify::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 playerid = 1;
    if (has_playerid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->playerid());
    }

    // optional int32 format = 2;
    if (has_format()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->format());
    }

    // optional int32 helperpos = 4;
    if (has_helperpos()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->helperpos());
    }

  }
  // repeated int64 fighter = 3;
  {
    int data_size = 0;
    for (int i = 0; i < this->fighter_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->fighter(i));
    }
    total_size += 1 * this->fighter_size() + data_size;
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

void FormatDebutNotify::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FormatDebutNotify* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FormatDebutNotify*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FormatDebutNotify::MergeFrom(const FormatDebutNotify& from) {
  GOOGLE_CHECK_NE(&from, this);
  fighter_.MergeFrom(from.fighter_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_playerid()) {
      set_playerid(from.playerid());
    }
    if (from.has_format()) {
      set_format(from.format());
    }
    if (from.has_helperpos()) {
      set_helperpos(from.helperpos());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FormatDebutNotify::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FormatDebutNotify::CopyFrom(const FormatDebutNotify& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FormatDebutNotify::IsInitialized() const {

  return true;
}

void FormatDebutNotify::Swap(FormatDebutNotify* other) {
  if (other != this) {
    std::swap(playerid_, other->playerid_);
    std::swap(format_, other->format_);
    fighter_.Swap(&other->fighter_);
    std::swap(helperpos_, other->helperpos_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FormatDebutNotify::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FormatDebutNotify_descriptor_;
  metadata.reflection = FormatDebutNotify_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
