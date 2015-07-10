// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageTaskSync.proto

#ifndef PROTOBUF_MessageTaskSync_2eproto__INCLUDED
#define PROTOBUF_MessageTaskSync_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessageTaskSync_2eproto();
void protobuf_AssignDesc_MessageTaskSync_2eproto();
void protobuf_ShutdownFile_MessageTaskSync_2eproto();

class Task;
class TaskSync;

// ===================================================================

class Task : public ::google::protobuf::Message {
 public:
  Task();
  virtual ~Task();

  Task(const Task& from);

  inline Task& operator=(const Task& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Task& default_instance();

  void Swap(Task* other);

  // implements Message ----------------------------------------------

  Task* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Task& from);
  void MergeFrom(const Task& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int64 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int64 id() const;
  inline void set_id(::google::protobuf::int64 value);

  // repeated int32 args = 2;
  inline int args_size() const;
  inline void clear_args();
  static const int kArgsFieldNumber = 2;
  inline ::google::protobuf::int32 args(int index) const;
  inline void set_args(int index, ::google::protobuf::int32 value);
  inline void add_args(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      args() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_args();

  // @@protoc_insertion_point(class_scope:Message.Task)
 private:
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 id_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > args_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_MessageTaskSync_2eproto();
  friend void protobuf_AssignDesc_MessageTaskSync_2eproto();
  friend void protobuf_ShutdownFile_MessageTaskSync_2eproto();

  void InitAsDefaultInstance();
  static Task* default_instance_;
};
// -------------------------------------------------------------------

class TaskSync : public ::google::protobuf::Message {
 public:
  TaskSync();
  virtual ~TaskSync();

  TaskSync(const TaskSync& from);

  inline TaskSync& operator=(const TaskSync& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TaskSync& default_instance();

  void Swap(TaskSync* other);

  // implements Message ----------------------------------------------

  TaskSync* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TaskSync& from);
  void MergeFrom(const TaskSync& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Message.Task tasks = 1;
  inline int tasks_size() const;
  inline void clear_tasks();
  static const int kTasksFieldNumber = 1;
  inline const ::Message::Task& tasks(int index) const;
  inline ::Message::Task* mutable_tasks(int index);
  inline ::Message::Task* add_tasks();
  inline const ::google::protobuf::RepeatedPtrField< ::Message::Task >&
      tasks() const;
  inline ::google::protobuf::RepeatedPtrField< ::Message::Task >*
      mutable_tasks();

  // @@protoc_insertion_point(class_scope:Message.TaskSync)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::Message::Task > tasks_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_MessageTaskSync_2eproto();
  friend void protobuf_AssignDesc_MessageTaskSync_2eproto();
  friend void protobuf_ShutdownFile_MessageTaskSync_2eproto();

  void InitAsDefaultInstance();
  static TaskSync* default_instance_;
};
// ===================================================================


// ===================================================================

// Task

// required int64 id = 1;
inline bool Task::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Task::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Task::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Task::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::int64 Task::id() const {
  return id_;
}
inline void Task::set_id(::google::protobuf::int64 value) {
  set_has_id();
  id_ = value;
}

// repeated int32 args = 2;
inline int Task::args_size() const {
  return args_.size();
}
inline void Task::clear_args() {
  args_.Clear();
}
inline ::google::protobuf::int32 Task::args(int index) const {
  return args_.Get(index);
}
inline void Task::set_args(int index, ::google::protobuf::int32 value) {
  args_.Set(index, value);
}
inline void Task::add_args(::google::protobuf::int32 value) {
  args_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Task::args() const {
  return args_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Task::mutable_args() {
  return &args_;
}

// -------------------------------------------------------------------

// TaskSync

// repeated .Message.Task tasks = 1;
inline int TaskSync::tasks_size() const {
  return tasks_.size();
}
inline void TaskSync::clear_tasks() {
  tasks_.Clear();
}
inline const ::Message::Task& TaskSync::tasks(int index) const {
  return tasks_.Get(index);
}
inline ::Message::Task* TaskSync::mutable_tasks(int index) {
  return tasks_.Mutable(index);
}
inline ::Message::Task* TaskSync::add_tasks() {
  return tasks_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Message::Task >&
TaskSync::tasks() const {
  return tasks_;
}
inline ::google::protobuf::RepeatedPtrField< ::Message::Task >*
TaskSync::mutable_tasks() {
  return &tasks_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageTaskSync_2eproto__INCLUDED
