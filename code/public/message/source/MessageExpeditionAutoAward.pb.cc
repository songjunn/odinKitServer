// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageExpeditionAutoAward.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageExpeditionAutoAward.pb.h"

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

const ::google::protobuf::Descriptor* ExpeditionAutoAward_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ExpeditionAutoAward_reflection_ = NULL;
const ::google::protobuf::Descriptor* ExpeditionAutoAward_AutoAward_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ExpeditionAutoAward_AutoAward_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageExpeditionAutoAward_2eproto() {
  protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageExpeditionAutoAward.proto");
  GOOGLE_CHECK(file != NULL);
  ExpeditionAutoAward_descriptor_ = file->message_type(0);
  static const int ExpeditionAutoAward_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward, autoawards_),
  };
  ExpeditionAutoAward_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ExpeditionAutoAward_descriptor_,
      ExpeditionAutoAward::default_instance_,
      ExpeditionAutoAward_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ExpeditionAutoAward));
  ExpeditionAutoAward_AutoAward_descriptor_ = ExpeditionAutoAward_descriptor_->nested_type(0);
  static const int ExpeditionAutoAward_AutoAward_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward_AutoAward, gainexp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward_AutoAward, gainsilver_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward_AutoAward, itemid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward_AutoAward, itemstack_),
  };
  ExpeditionAutoAward_AutoAward_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ExpeditionAutoAward_AutoAward_descriptor_,
      ExpeditionAutoAward_AutoAward::default_instance_,
      ExpeditionAutoAward_AutoAward_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward_AutoAward, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ExpeditionAutoAward_AutoAward, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ExpeditionAutoAward_AutoAward));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageExpeditionAutoAward_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ExpeditionAutoAward_descriptor_, &ExpeditionAutoAward::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ExpeditionAutoAward_AutoAward_descriptor_, &ExpeditionAutoAward_AutoAward::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageExpeditionAutoAward_2eproto() {
  delete ExpeditionAutoAward::default_instance_;
  delete ExpeditionAutoAward_reflection_;
  delete ExpeditionAutoAward_AutoAward::default_instance_;
  delete ExpeditionAutoAward_AutoAward_reflection_;
}

void protobuf_AddDesc_MessageExpeditionAutoAward_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n MessageExpeditionAutoAward.proto\022\007Mess"
    "age\"\246\001\n\023ExpeditionAutoAward\022:\n\nautoaward"
    "s\030\001 \003(\0132&.Message.ExpeditionAutoAward.Au"
    "toAward\032S\n\tAutoAward\022\017\n\007gainexp\030\001 \001(\005\022\022\n"
    "\ngainsilver\030\003 \001(\005\022\016\n\006itemid\030\004 \003(\005\022\021\n\tite"
    "mstack\030\005 \003(\005", 212);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageExpeditionAutoAward.proto", &protobuf_RegisterTypes);
  ExpeditionAutoAward::default_instance_ = new ExpeditionAutoAward();
  ExpeditionAutoAward_AutoAward::default_instance_ = new ExpeditionAutoAward_AutoAward();
  ExpeditionAutoAward::default_instance_->InitAsDefaultInstance();
  ExpeditionAutoAward_AutoAward::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageExpeditionAutoAward_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageExpeditionAutoAward_2eproto {
  StaticDescriptorInitializer_MessageExpeditionAutoAward_2eproto() {
    protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
  }
} static_descriptor_initializer_MessageExpeditionAutoAward_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ExpeditionAutoAward_AutoAward::kGainexpFieldNumber;
const int ExpeditionAutoAward_AutoAward::kGainsilverFieldNumber;
const int ExpeditionAutoAward_AutoAward::kItemidFieldNumber;
const int ExpeditionAutoAward_AutoAward::kItemstackFieldNumber;
#endif  // !_MSC_VER

ExpeditionAutoAward_AutoAward::ExpeditionAutoAward_AutoAward()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ExpeditionAutoAward_AutoAward::InitAsDefaultInstance() {
}

ExpeditionAutoAward_AutoAward::ExpeditionAutoAward_AutoAward(const ExpeditionAutoAward_AutoAward& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ExpeditionAutoAward_AutoAward::SharedCtor() {
  _cached_size_ = 0;
  gainexp_ = 0;
  gainsilver_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ExpeditionAutoAward_AutoAward::~ExpeditionAutoAward_AutoAward() {
  SharedDtor();
}

void ExpeditionAutoAward_AutoAward::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ExpeditionAutoAward_AutoAward::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ExpeditionAutoAward_AutoAward::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ExpeditionAutoAward_AutoAward_descriptor_;
}

const ExpeditionAutoAward_AutoAward& ExpeditionAutoAward_AutoAward::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
  return *default_instance_;
}

ExpeditionAutoAward_AutoAward* ExpeditionAutoAward_AutoAward::default_instance_ = NULL;

ExpeditionAutoAward_AutoAward* ExpeditionAutoAward_AutoAward::New() const {
  return new ExpeditionAutoAward_AutoAward;
}

void ExpeditionAutoAward_AutoAward::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    gainexp_ = 0;
    gainsilver_ = 0;
  }
  itemid_.Clear();
  itemstack_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ExpeditionAutoAward_AutoAward::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 gainexp = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &gainexp_)));
          set_has_gainexp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_gainsilver;
        break;
      }

      // optional int32 gainsilver = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_gainsilver:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &gainsilver_)));
          set_has_gainsilver();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_itemid;
        break;
      }

      // repeated int32 itemid = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_itemid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 32, input, this->mutable_itemid())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_itemid())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_itemid;
        if (input->ExpectTag(40)) goto parse_itemstack;
        break;
      }

      // repeated int32 itemstack = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_itemstack:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 40, input, this->mutable_itemstack())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_itemstack())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_itemstack;
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

void ExpeditionAutoAward_AutoAward::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 gainexp = 1;
  if (has_gainexp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->gainexp(), output);
  }

  // optional int32 gainsilver = 3;
  if (has_gainsilver()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->gainsilver(), output);
  }

  // repeated int32 itemid = 4;
  for (int i = 0; i < this->itemid_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      4, this->itemid(i), output);
  }

  // repeated int32 itemstack = 5;
  for (int i = 0; i < this->itemstack_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      5, this->itemstack(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ExpeditionAutoAward_AutoAward::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 gainexp = 1;
  if (has_gainexp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->gainexp(), target);
  }

  // optional int32 gainsilver = 3;
  if (has_gainsilver()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->gainsilver(), target);
  }

  // repeated int32 itemid = 4;
  for (int i = 0; i < this->itemid_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(4, this->itemid(i), target);
  }

  // repeated int32 itemstack = 5;
  for (int i = 0; i < this->itemstack_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(5, this->itemstack(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ExpeditionAutoAward_AutoAward::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 gainexp = 1;
    if (has_gainexp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->gainexp());
    }

    // optional int32 gainsilver = 3;
    if (has_gainsilver()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->gainsilver());
    }

  }
  // repeated int32 itemid = 4;
  {
    int data_size = 0;
    for (int i = 0; i < this->itemid_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->itemid(i));
    }
    total_size += 1 * this->itemid_size() + data_size;
  }

  // repeated int32 itemstack = 5;
  {
    int data_size = 0;
    for (int i = 0; i < this->itemstack_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->itemstack(i));
    }
    total_size += 1 * this->itemstack_size() + data_size;
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

void ExpeditionAutoAward_AutoAward::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ExpeditionAutoAward_AutoAward* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ExpeditionAutoAward_AutoAward*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ExpeditionAutoAward_AutoAward::MergeFrom(const ExpeditionAutoAward_AutoAward& from) {
  GOOGLE_CHECK_NE(&from, this);
  itemid_.MergeFrom(from.itemid_);
  itemstack_.MergeFrom(from.itemstack_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_gainexp()) {
      set_gainexp(from.gainexp());
    }
    if (from.has_gainsilver()) {
      set_gainsilver(from.gainsilver());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ExpeditionAutoAward_AutoAward::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ExpeditionAutoAward_AutoAward::CopyFrom(const ExpeditionAutoAward_AutoAward& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ExpeditionAutoAward_AutoAward::IsInitialized() const {

  return true;
}

void ExpeditionAutoAward_AutoAward::Swap(ExpeditionAutoAward_AutoAward* other) {
  if (other != this) {
    std::swap(gainexp_, other->gainexp_);
    std::swap(gainsilver_, other->gainsilver_);
    itemid_.Swap(&other->itemid_);
    itemstack_.Swap(&other->itemstack_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ExpeditionAutoAward_AutoAward::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ExpeditionAutoAward_AutoAward_descriptor_;
  metadata.reflection = ExpeditionAutoAward_AutoAward_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int ExpeditionAutoAward::kAutoawardsFieldNumber;
#endif  // !_MSC_VER

ExpeditionAutoAward::ExpeditionAutoAward()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ExpeditionAutoAward::InitAsDefaultInstance() {
}

ExpeditionAutoAward::ExpeditionAutoAward(const ExpeditionAutoAward& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ExpeditionAutoAward::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ExpeditionAutoAward::~ExpeditionAutoAward() {
  SharedDtor();
}

void ExpeditionAutoAward::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ExpeditionAutoAward::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ExpeditionAutoAward::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ExpeditionAutoAward_descriptor_;
}

const ExpeditionAutoAward& ExpeditionAutoAward::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
  return *default_instance_;
}

ExpeditionAutoAward* ExpeditionAutoAward::default_instance_ = NULL;

ExpeditionAutoAward* ExpeditionAutoAward::New() const {
  return new ExpeditionAutoAward;
}

void ExpeditionAutoAward::Clear() {
  autoawards_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ExpeditionAutoAward::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Message.ExpeditionAutoAward.AutoAward autoawards = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_autoawards:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_autoawards()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_autoawards;
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

void ExpeditionAutoAward::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Message.ExpeditionAutoAward.AutoAward autoawards = 1;
  for (int i = 0; i < this->autoawards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->autoawards(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ExpeditionAutoAward::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Message.ExpeditionAutoAward.AutoAward autoawards = 1;
  for (int i = 0; i < this->autoawards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->autoawards(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ExpeditionAutoAward::ByteSize() const {
  int total_size = 0;

  // repeated .Message.ExpeditionAutoAward.AutoAward autoawards = 1;
  total_size += 1 * this->autoawards_size();
  for (int i = 0; i < this->autoawards_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->autoawards(i));
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

void ExpeditionAutoAward::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ExpeditionAutoAward* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ExpeditionAutoAward*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ExpeditionAutoAward::MergeFrom(const ExpeditionAutoAward& from) {
  GOOGLE_CHECK_NE(&from, this);
  autoawards_.MergeFrom(from.autoawards_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ExpeditionAutoAward::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ExpeditionAutoAward::CopyFrom(const ExpeditionAutoAward& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ExpeditionAutoAward::IsInitialized() const {

  return true;
}

void ExpeditionAutoAward::Swap(ExpeditionAutoAward* other) {
  if (other != this) {
    autoawards_.Swap(&other->autoawards_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ExpeditionAutoAward::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ExpeditionAutoAward_descriptor_;
  metadata.reflection = ExpeditionAutoAward_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
