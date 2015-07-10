// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageSyncObjField.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageSyncObjField.pb.h"

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

const ::google::protobuf::Descriptor* SyncObjField_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SyncObjField_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageSyncObjField_2eproto() {
  protobuf_AddDesc_MessageSyncObjField_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageSyncObjField.proto");
  GOOGLE_CHECK(file != NULL);
  SyncObjField_descriptor_ = file->message_type(0);
  static const int SyncObjField_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, mapkey_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, jsonstr_),
  };
  SyncObjField_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SyncObjField_descriptor_,
      SyncObjField::default_instance_,
      SyncObjField_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncObjField, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SyncObjField));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageSyncObjField_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SyncObjField_descriptor_, &SyncObjField::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageSyncObjField_2eproto() {
  delete SyncObjField::default_instance_;
  delete SyncObjField_reflection_;
}

void protobuf_AddDesc_MessageSyncObjField_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\031MessageSyncObjField.proto\022\007Message\"V\n\014"
    "SyncObjField\022\n\n\002id\030\001 \001(\003\022\014\n\004type\030\002 \001(\t\022\013"
    "\n\003key\030\003 \001(\t\022\016\n\006mapkey\030\004 \001(\003\022\017\n\007jsonstr\030\005"
    " \001(\t", 124);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageSyncObjField.proto", &protobuf_RegisterTypes);
  SyncObjField::default_instance_ = new SyncObjField();
  SyncObjField::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageSyncObjField_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageSyncObjField_2eproto {
  StaticDescriptorInitializer_MessageSyncObjField_2eproto() {
    protobuf_AddDesc_MessageSyncObjField_2eproto();
  }
} static_descriptor_initializer_MessageSyncObjField_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SyncObjField::kIdFieldNumber;
const int SyncObjField::kTypeFieldNumber;
const int SyncObjField::kKeyFieldNumber;
const int SyncObjField::kMapkeyFieldNumber;
const int SyncObjField::kJsonstrFieldNumber;
#endif  // !_MSC_VER

SyncObjField::SyncObjField()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SyncObjField::InitAsDefaultInstance() {
}

SyncObjField::SyncObjField(const SyncObjField& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SyncObjField::SharedCtor() {
  _cached_size_ = 0;
  id_ = GOOGLE_LONGLONG(0);
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  mapkey_ = GOOGLE_LONGLONG(0);
  jsonstr_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SyncObjField::~SyncObjField() {
  SharedDtor();
}

void SyncObjField::SharedDtor() {
  if (type_ != &::google::protobuf::internal::kEmptyString) {
    delete type_;
  }
  if (key_ != &::google::protobuf::internal::kEmptyString) {
    delete key_;
  }
  if (jsonstr_ != &::google::protobuf::internal::kEmptyString) {
    delete jsonstr_;
  }
  if (this != default_instance_) {
  }
}

void SyncObjField::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SyncObjField::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SyncObjField_descriptor_;
}

const SyncObjField& SyncObjField::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageSyncObjField_2eproto();
  return *default_instance_;
}

SyncObjField* SyncObjField::default_instance_ = NULL;

SyncObjField* SyncObjField::New() const {
  return new SyncObjField;
}

void SyncObjField::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = GOOGLE_LONGLONG(0);
    if (has_type()) {
      if (type_ != &::google::protobuf::internal::kEmptyString) {
        type_->clear();
      }
    }
    if (has_key()) {
      if (key_ != &::google::protobuf::internal::kEmptyString) {
        key_->clear();
      }
    }
    mapkey_ = GOOGLE_LONGLONG(0);
    if (has_jsonstr()) {
      if (jsonstr_ != &::google::protobuf::internal::kEmptyString) {
        jsonstr_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SyncObjField::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_type;
        break;
      }

      // optional string type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->type().data(), this->type().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_key;
        break;
      }

      // optional string key = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_key()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->key().data(), this->key().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_mapkey;
        break;
      }

      // optional int64 mapkey = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_mapkey:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &mapkey_)));
          set_has_mapkey();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_jsonstr;
        break;
      }

      // optional string jsonstr = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_jsonstr:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_jsonstr()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->jsonstr().data(), this->jsonstr().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void SyncObjField::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->id(), output);
  }

  // optional string type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->type(), output);
  }

  // optional string key = 3;
  if (has_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->key(), output);
  }

  // optional int64 mapkey = 4;
  if (has_mapkey()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->mapkey(), output);
  }

  // optional string jsonstr = 5;
  if (has_jsonstr()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->jsonstr().data(), this->jsonstr().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->jsonstr(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SyncObjField::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->id(), target);
  }

  // optional string type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->type(), target);
  }

  // optional string key = 3;
  if (has_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->key(), target);
  }

  // optional int64 mapkey = 4;
  if (has_mapkey()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->mapkey(), target);
  }

  // optional string jsonstr = 5;
  if (has_jsonstr()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->jsonstr().data(), this->jsonstr().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->jsonstr(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SyncObjField::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->id());
    }

    // optional string type = 2;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->type());
    }

    // optional string key = 3;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->key());
    }

    // optional int64 mapkey = 4;
    if (has_mapkey()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->mapkey());
    }

    // optional string jsonstr = 5;
    if (has_jsonstr()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->jsonstr());
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

void SyncObjField::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SyncObjField* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SyncObjField*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SyncObjField::MergeFrom(const SyncObjField& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_key()) {
      set_key(from.key());
    }
    if (from.has_mapkey()) {
      set_mapkey(from.mapkey());
    }
    if (from.has_jsonstr()) {
      set_jsonstr(from.jsonstr());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SyncObjField::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SyncObjField::CopyFrom(const SyncObjField& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SyncObjField::IsInitialized() const {

  return true;
}

void SyncObjField::Swap(SyncObjField* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(type_, other->type_);
    std::swap(key_, other->key_);
    std::swap(mapkey_, other->mapkey_);
    std::swap(jsonstr_, other->jsonstr_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SyncObjField::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SyncObjField_descriptor_;
  metadata.reflection = SyncObjField_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
