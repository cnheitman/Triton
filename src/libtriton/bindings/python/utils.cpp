//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the Apache License 2.0.
*/


#include <triton/pythonBindings.hpp>
#include <triton/pythonUtils.hpp>
#include <triton/exceptions.hpp>
#include <triton/tritonTypes.hpp>

#include <limits>


namespace triton {
  namespace bindings {
    namespace python {

      bool PyLong_AsBool(PyObject* obj) {
        return (PyObject_IsTrue(obj) != 0);
      }

      triton::__uint PyLong_AsUint(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint(): Bad internal call.");
        }

        triton::__uint value = (triton::__uint) std::strtoul(str_value, 0, 10);

        Py_DECREF(py_str);

        return value;
      }


      triton::usize PyLong_AsUsize(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUsize(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUsize(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUsize(): Bad internal call.");
        }

        triton::usize value = (triton::usize) std::strtoull(str_value, 0, 10);

        Py_DECREF(py_str);

        return value;
      }


      triton::uint32 PyLong_AsUint32(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint32(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint32(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint32(): Bad internal call.");
        }

        triton::uint32 value = std::strtoul(str_value, 0, 10);

        Py_DECREF(py_str);

        return value;
      }


      triton::uint64 PyLong_AsUint64(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint64(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint64(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint64(): Bad internal call.");
        }

        triton::uint64 value = std::strtoull(str_value, 0, 10);

        Py_DECREF(py_str);

        return value;
      }


      triton::uint128 PyLong_AsUint128(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint128(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint128(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint128(): Bad internal call.");
        }

        triton::uint128 value = triton::uint128(str_value);

        Py_DECREF(py_str);

        return value;
      }


      triton::uint256 PyLong_AsUint256(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint256(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint256(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint256(): Bad internal call.");
        }

        triton::uint256 value = triton::uint256(str_value);

        Py_DECREF(py_str);

        return value;
      }


      triton::uint512 PyLong_AsUint512(PyObject* vv) {
        if (vv == NULL || !PyLong_Check(vv)) {
          if (vv != NULL && PyInt_Check(vv)) {
            return PyInt_AsLong(vv);
          }
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint512(): Bad internal call.");
        }

        // Convert PyLong to string
        PyObject* py_str = PyObject_Str(vv);
        if (!py_str) {
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint512(): Bad internal call.");
        }

        const char* str_value = PyUnicode_AsUTF8(py_str);
        if (!str_value) {
          Py_DECREF(py_str);
          throw triton::exceptions::Bindings("triton::bindings::python::PyLong_AsUint512(): Bad internal call.");
        }

        triton::uint512 value = triton::uint512(str_value);

        Py_DECREF(py_str);

        return value;
      }


      /* Returns a PyObject from a {32,64}-bits integer */
      PyObject* PyLong_FromUint(triton::__uint value) {
        #if defined(__i386) || defined(_M_IX86)
        return PyInt_FromLong(static_cast<long>(value));
        #else
        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        std::ostringstream oss;
        oss << value;
        std::string value_str = oss.str();

        // Create a PyLong from the string
        PyObject* py_long = PyLong_FromString(value_str.c_str(), nullptr, 10);
        if (!py_long) {
          throw std::runtime_error("Failed to convert triton::__uint  to PyLong");
        }

        return py_long;
        #endif
      }


      /* Returns a PyObject from a {32,64}-bits integer */
      PyObject* PyLong_FromUsize(triton::usize value) {
        #if defined(__i386) || defined(_M_IX86)
        return PyInt_FromLong(static_cast<long>(value));
        #else
        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        std::ostringstream oss;
        oss << value;
        std::string value_str = oss.str();

        // Create a PyLong from the string
        PyObject* py_long = PyLong_FromString(value_str.c_str(), nullptr, 10);
        if (!py_long) {
          throw std::runtime_error("Failed to convert triton::usize to PyLong");
        }

        return py_long;
        #endif
      }


      /* Returns a PyObject from a 32-bits integer */
      PyObject* PyLong_FromUint32(triton::uint32 value) {
        return PyInt_FromLong(static_cast<long>(value));
      }


      /* Returns a PyObject from a 64-bits integer */
      PyObject* PyLong_FromUint64(triton::uint64 value) {
        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        std::ostringstream oss;
        oss << value;
        std::string value_str = oss.str();

        // Create a PyLong from the string
        PyObject* py_long = PyLong_FromString(value_str.c_str(), nullptr, 10);
        if (!py_long) {
          throw std::runtime_error("Failed to convert triton::uint32 to PyLong");
        }

        return py_long;
      }


      /* Returns a PyObject from a 128-bits integer */
      PyObject* PyLong_FromUint256(triton::uint128 value) {
        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        std::ostringstream oss;
        oss << value;
        std::string value_str = oss.str();

        // Create a PyLong from the string
        PyObject* py_long = PyLong_FromString(value_str.c_str(), nullptr, 10);
        if (!py_long) {
          throw std::runtime_error("Failed to convert triton::uint128 to PyLong");
        }

        return py_long;
      }


      /* Returns a PyObject from a 256-bits integer */
      PyObject* PyLong_FromUint256(triton::uint256 value) {
        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        std::ostringstream oss;
        oss << value;
        std::string value_str = oss.str();

        // Create a PyLong from the string
        PyObject* py_long = PyLong_FromString(value_str.c_str(), nullptr, 10);
        if (!py_long) {
          throw std::runtime_error("Failed to convert triton::uint256 to PyLong");
        }

        return py_long;
      }


      /* Returns a PyObject from a 256-bits integer */
      PyObject* PyLong_FromUint512(triton::uint512 value) {
        // it is mandatory to let Python deal with small numbers (static objects)
        if (value <= std::numeric_limits<long>::max())
          return PyInt_FromLong(static_cast<long>(value));

        std::ostringstream oss;
        oss << value;
        std::string value_str = oss.str();

        // Create a PyLong from the string
        PyObject* py_long = PyLong_FromString(value_str.c_str(), nullptr, 10);
        if (!py_long) {
          throw std::runtime_error("Failed to convert triton::uint512 to PyLong");
        }

        return py_long;
      }

    }; /* python namespace */
  }; /* bindings namespace */
}; /* triton namespace */
