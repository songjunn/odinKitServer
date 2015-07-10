// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageUserLogin.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageUserLogin.pb.h"

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

const ::google::protobuf::Descriptor* UserLogin_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UserLogin_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageUserLogin_2eproto() {
  protobuf_AddDesc_MessageUserLogin_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageUserLogin.proto");
  GOOGLE_CHECK(file != NULL);
  UserLogin_descriptor_ = file->message_type(0);
  static const int UserLogin_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, uid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, world_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, server_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, key_),
  };
  UserLogin_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UserLogin_descriptor_,
      UserLogin::default_instance_,
      UserLogin_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserLogin, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UserLogin));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageUserLogin_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UserLogin_descriptor_, &UserLogin::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageUserLogin_2eproto() {
  delete UserLogin::default_instance_;
  delete UserLogin_reflection_;
}

void protobuf_AddDesc_MessageUserLogin_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026MessageUserLogin.proto\022\007Message\"R\n\tUse"
    "rLogin\022\013\n\003uid\030\001 \001(\003\022\r\n\005world\030\002 \001(\005\022\016\n\006se"
    "rver\030\003 \001(\005\022\014\n\004type\030\004 \001(\t\022\013\n\003key\030\005 \001(\t", 117);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageUserLogin.proto", &protobuf_RegisterTypes);
  UserLogin::default_instance_ = new UserLogin();
  UserLogin::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageUserLogin_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageUserLogin_2eproto {
  StaticDescriptorInitializer_MessageUserLogin_2eproto() {
    protobuf_AddDesc_MessageUserLogin_2eproto();
  }
} static_descriptor_initializer_MessageUserLogin_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int UserLogin::kUidFieldNumber;
const int UserLogin::kWorldFieldNumber;
const int UserLogin::kServerFieldNumber;
const int UserLogin::kTypeFieldNumber;
const int UserLogin::kKeyFieldNumber;
#endif  // !_MSC_VER

UserLogin::UserLogin()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void UserLogin::InitAsDefaultInstance() {
}

UserLogin::UserLogin(const UserLogin& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void UserLogin::SharedCtor() {
  _cached_size_ = 0;
  uid_ = GOOGLE_LONGLONG(0);
  world_ = 0;
  server_ = 0;
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UserLogin::~UserLogin() {
  SharedDtor();
}

void UserLogin::SharedDtor() {
  if (type_ != &::google::protobuf::internal::kEmptyString) {
    delete type_;
  }
  if (key_ != &::google::protobuf::internal::kEmptyString) {
    delete key_;
  }
  if (this != default_instance_) {
  }
}

void UserLogin::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UserLogin::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserLogin_descriptor_;
}

const UserLogin& UserLogin::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageUserLogin_2eproto();
  return *default_instance_;
}

UserLogin* UserLogin::default_instance_ = NULL;

UserLogin* UserLogin::New() const {
  return new UserLogin;
}

void UserLogin::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    uid_ = GOOGLE_LONGLONG(0);
    world_ = 0;
    server_ = 0;
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
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UserLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 uid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &uid_)));
          set_has_uid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_world;
        break;
      }

      // optional int32 world = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_world:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &world_)));
          set_has_world();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_server;
        break;
      }

      // optional int32 server = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_server:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &server_)));
          set_has_server();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_type;
        break;
      }

      // optional string type = 4;
      case 4: {
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
        if (input->ExpectTag(42)) goto parse_key;
        break;
      }

      // optional string key = 5;
      case 5: {
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

void UserLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 uid = 1;
  if (has_uid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->uid(), output);
  }

  // optional int32 world = 2;
  if (has_world()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->world(), output);
  }

  // optional int32 server = 3;
  if (has_server()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->server(), output);
  }

  // optional string type = 4;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->type(), output);
  }

  // optional string key = 5;
  if (has_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->key(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* UserLogin::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 uid = 1;
  if (has_uid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->uid(), target);
  }

  // optional int32 world = 2;
  if (has_world()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->world(), target);
  }

  // optional int32 server = 3;
  if (has_server()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->server(), target);
  }

  // optional string type = 4;
  if (has_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->type().data(), this->type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->type(), target);
  }

  // optional string key = 5;
  if (has_key()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->key(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int UserLogin::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 uid = 1;
    if (has_uid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->uid());
    }

    // optional int32 world = 2;
    if (has_world()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->world());
    }

    // optional int32 server = 3;
    if (has_server()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->server());
    }

    // optional string type = 4;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->type());
    }

    // optional string key = 5;
    if (has_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->key());
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

void UserLogin::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UserLogin* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UserLogin*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UserLogin::MergeFrom(const UserLogin& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_uid()) {
      set_uid(from.uid());
    }
    if (from.has_world()) {
      set_world(from.world());
    }
    if (from.has_server()) {
      set_server(from.server());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_key()) {
      set_key(from.key());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UserLogin::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserLogin::CopyFrom(const UserLogin& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserLogin::IsInitialized() const {

  return true;
}

void UserLogin::Swap(UserLogin* other) {
  if (other != this) {
    std::swap(uid_, other->uid_);
    std::swap(world_, other->world_);
    std::swap(server_, other->server_);
    std::swap(type_, other->type_);
    std::swap(key_, other->key_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UserLogin::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UserLogin_descriptor_;
  metadata.reflection = UserLogin_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
