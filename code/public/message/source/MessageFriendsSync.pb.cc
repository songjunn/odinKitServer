// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageFriendsSync.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageFriendsSync.pb.h"

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

const ::google::protobuf::Descriptor* FriendsSync_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FriendsSync_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageFriendsSync_2eproto() {
  protobuf_AddDesc_MessageFriendsSync_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageFriendsSync.proto");
  GOOGLE_CHECK(file != NULL);
  FriendsSync_descriptor_ = file->message_type(0);
  static const int FriendsSync_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendsSync, friend__),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendsSync, request_),
  };
  FriendsSync_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FriendsSync_descriptor_,
      FriendsSync::default_instance_,
      FriendsSync_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendsSync, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendsSync, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FriendsSync));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageFriendsSync_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FriendsSync_descriptor_, &FriendsSync::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageFriendsSync_2eproto() {
  delete FriendsSync::default_instance_;
  delete FriendsSync_reflection_;
}

void protobuf_AddDesc_MessageFriendsSync_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Message::protobuf_AddDesc_MessageFriend_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\030MessageFriendsSync.proto\022\007Message\032\023Mes"
    "sageFriend.proto\"P\n\013FriendsSync\022\037\n\006frien"
    "d\030\001 \003(\0132\017.Message.Friend\022 \n\007request\030\002 \003("
    "\0132\017.Message.Friend", 138);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageFriendsSync.proto", &protobuf_RegisterTypes);
  FriendsSync::default_instance_ = new FriendsSync();
  FriendsSync::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageFriendsSync_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageFriendsSync_2eproto {
  StaticDescriptorInitializer_MessageFriendsSync_2eproto() {
    protobuf_AddDesc_MessageFriendsSync_2eproto();
  }
} static_descriptor_initializer_MessageFriendsSync_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int FriendsSync::kFriendFieldNumber;
const int FriendsSync::kRequestFieldNumber;
#endif  // !_MSC_VER

FriendsSync::FriendsSync()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void FriendsSync::InitAsDefaultInstance() {
}

FriendsSync::FriendsSync(const FriendsSync& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void FriendsSync::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FriendsSync::~FriendsSync() {
  SharedDtor();
}

void FriendsSync::SharedDtor() {
  if (this != default_instance_) {
  }
}

void FriendsSync::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FriendsSync::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendsSync_descriptor_;
}

const FriendsSync& FriendsSync::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFriendsSync_2eproto();
  return *default_instance_;
}

FriendsSync* FriendsSync::default_instance_ = NULL;

FriendsSync* FriendsSync::New() const {
  return new FriendsSync;
}

void FriendsSync::Clear() {
  friend__.Clear();
  request_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FriendsSync::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Message.Friend friend = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_friend:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_friend_()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_friend;
        if (input->ExpectTag(18)) goto parse_request;
        break;
      }

      // repeated .Message.Friend request = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_request:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_request()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_request;
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

void FriendsSync::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Message.Friend friend = 1;
  for (int i = 0; i < this->friend__size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->friend_(i), output);
  }

  // repeated .Message.Friend request = 2;
  for (int i = 0; i < this->request_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->request(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* FriendsSync::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Message.Friend friend = 1;
  for (int i = 0; i < this->friend__size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->friend_(i), target);
  }

  // repeated .Message.Friend request = 2;
  for (int i = 0; i < this->request_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->request(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int FriendsSync::ByteSize() const {
  int total_size = 0;

  // repeated .Message.Friend friend = 1;
  total_size += 1 * this->friend__size();
  for (int i = 0; i < this->friend__size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->friend_(i));
  }

  // repeated .Message.Friend request = 2;
  total_size += 1 * this->request_size();
  for (int i = 0; i < this->request_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->request(i));
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

void FriendsSync::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FriendsSync* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FriendsSync*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FriendsSync::MergeFrom(const FriendsSync& from) {
  GOOGLE_CHECK_NE(&from, this);
  friend__.MergeFrom(from.friend__);
  request_.MergeFrom(from.request_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FriendsSync::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FriendsSync::CopyFrom(const FriendsSync& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FriendsSync::IsInitialized() const {

  return true;
}

void FriendsSync::Swap(FriendsSync* other) {
  if (other != this) {
    friend__.Swap(&other->friend__);
    request_.Swap(&other->request_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FriendsSync::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FriendsSync_descriptor_;
  metadata.reflection = FriendsSync_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
