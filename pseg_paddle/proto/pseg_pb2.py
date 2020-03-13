# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/pseg.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/pseg.proto',
  package='pseg',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x10proto/pseg.proto\x12\x04pseg\"\x1a\n\nPosRequest\x12\x0c\n\x04text\x18\x01 \x01(\t\"\"\n\x04Pair\x12\x0c\n\x04word\x18\x01 \x01(\t\x12\x0c\n\x04\x66lag\x18\x02 \x01(\t\"(\n\x0bPosResponse\x12\x19\n\x05pairs\x18\x01 \x03(\x0b\x32\n.pseg.Pair2@\n\x0cPartOfSpeech\x12\x30\n\x07Predict\x12\x10.pseg.PosRequest\x1a\x11.pseg.PosResponse\"\x00\x62\x06proto3')
)




_POSREQUEST = _descriptor.Descriptor(
  name='PosRequest',
  full_name='pseg.PosRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='text', full_name='pseg.PosRequest.text', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=26,
  serialized_end=52,
)


_PAIR = _descriptor.Descriptor(
  name='Pair',
  full_name='pseg.Pair',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='word', full_name='pseg.Pair.word', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='flag', full_name='pseg.Pair.flag', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=54,
  serialized_end=88,
)


_POSRESPONSE = _descriptor.Descriptor(
  name='PosResponse',
  full_name='pseg.PosResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='pairs', full_name='pseg.PosResponse.pairs', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=90,
  serialized_end=130,
)

_POSRESPONSE.fields_by_name['pairs'].message_type = _PAIR
DESCRIPTOR.message_types_by_name['PosRequest'] = _POSREQUEST
DESCRIPTOR.message_types_by_name['Pair'] = _PAIR
DESCRIPTOR.message_types_by_name['PosResponse'] = _POSRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

PosRequest = _reflection.GeneratedProtocolMessageType('PosRequest', (_message.Message,), {
  'DESCRIPTOR' : _POSREQUEST,
  '__module__' : 'proto.pseg_pb2'
  # @@protoc_insertion_point(class_scope:pseg.PosRequest)
  })
_sym_db.RegisterMessage(PosRequest)

Pair = _reflection.GeneratedProtocolMessageType('Pair', (_message.Message,), {
  'DESCRIPTOR' : _PAIR,
  '__module__' : 'proto.pseg_pb2'
  # @@protoc_insertion_point(class_scope:pseg.Pair)
  })
_sym_db.RegisterMessage(Pair)

PosResponse = _reflection.GeneratedProtocolMessageType('PosResponse', (_message.Message,), {
  'DESCRIPTOR' : _POSRESPONSE,
  '__module__' : 'proto.pseg_pb2'
  # @@protoc_insertion_point(class_scope:pseg.PosResponse)
  })
_sym_db.RegisterMessage(PosResponse)



_PARTOFSPEECH = _descriptor.ServiceDescriptor(
  name='PartOfSpeech',
  full_name='pseg.PartOfSpeech',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=132,
  serialized_end=196,
  methods=[
  _descriptor.MethodDescriptor(
    name='Predict',
    full_name='pseg.PartOfSpeech.Predict',
    index=0,
    containing_service=None,
    input_type=_POSREQUEST,
    output_type=_POSRESPONSE,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_PARTOFSPEECH)

DESCRIPTOR.services_by_name['PartOfSpeech'] = _PARTOFSPEECH

# @@protoc_insertion_point(module_scope)
