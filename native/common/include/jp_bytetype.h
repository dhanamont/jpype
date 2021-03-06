/*****************************************************************************
   Copyright 2004 Steve Ménard

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
*****************************************************************************/   
#ifndef _JPBYTE_TYPE_H_
#define _JPBYTE_TYPE_H_

class JPByteType : public JPPrimitiveType
{
public :
	JPByteType() : JPPrimitiveType(JPTypeName::_byte, false, JPTypeName::fromSimple("java.lang.Byte"))
	{
	}
	
	virtual ~JPByteType()
	{
	}

public :
	typedef jbyte type_t;
	typedef jbyteArray array_t;
	inline jbyte& field(jvalue& v) { return v.b; }
	inline jbyte field(const jvalue& v) const { return v.b; }

public : // JPType implementation
	virtual HostRef*   getStaticValue(JPJavaFrame& frame, jclass c, jfieldID fid, JPTypeName& tgtType);
	virtual void       setStaticValue(JPJavaFrame& frame, jclass c, jfieldID fid, HostRef* val);
	virtual HostRef*   getInstanceValue(JPJavaFrame& frame, jobject c, jfieldID fid, JPTypeName& tgtType);
	virtual void       setInstanceValue(JPJavaFrame& frame, jobject c, jfieldID fid, HostRef* val);
	virtual HostRef*   asHostObject(jvalue val);
	virtual HostRef*   asHostObjectFromObject(jvalue val);
	virtual EMatchType canConvertToJava(HostRef* obj);
	virtual jvalue     convertToJava(HostRef* obj);
	
	virtual HostRef*  invokeStatic(JPJavaFrame& frame, jclass, jmethodID, jvalue*);
	virtual HostRef*  invoke(JPJavaFrame& frame, jobject, jclass, jmethodID, jvalue*);

	virtual jarray    newArrayInstance(JPJavaFrame& frame, int size);
	virtual vector<HostRef*> getArrayRange(JPJavaFrame& frame, jarray, int start, int length);
	virtual void      setArrayRange(JPJavaFrame& frame, jarray, int start, int length, vector<HostRef*>& vals);
	virtual void      setArrayRange(JPJavaFrame& frame, jarray, int, int, PyObject*);
	virtual HostRef*  getArrayItem(JPJavaFrame& frame, jarray, int ndx);
	virtual void      setArrayItem(JPJavaFrame& frame, jarray, int ndx, HostRef* val);
	// this returns tuple instead of list, for performance reasons
	virtual PyObject* getArrayRangeToSequence(JPJavaFrame& frame, jarray, int start, int length);

	virtual HostRef*   convertToDirectBuffer(HostRef* src);

	virtual bool isSubTypeOf(const JPType& other) const
	{
		JPTypeName::ETypes otherType = other.getName().getType();
		return otherType == JPTypeName::_byte
				|| otherType == JPTypeName::_short
				|| otherType == JPTypeName::_int
				|| otherType == JPTypeName::_long
				|| otherType == JPTypeName::_float
				|| otherType == JPTypeName::_double;
	}
};

#endif // _JPBYTE_TYPE_H_

