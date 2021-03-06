/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Christian Schulte, 2008
 *
 *  Last modified:
 *     $Date: 2010-07-28 17:35:33 +0200 (Wed, 28 Jul 2010) $ by $Author: schulte $
 *     $Revision: 11294 $
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

namespace Gecode { namespace Iter { namespace Values {

  /**
   * \brief Value iterator for selecting only positive values
   *
   * If \a strict is true, zero is included.
   * \ingroup FuncIterValues
   */
  template<class I, bool strict=false>
  class Positive {
  protected:
    /// Input iterator
    I i;
  public:
    /// \name Constructors and initialization
    //@{
    /// Default constructor
    Positive(void);
    /// Initialize with values from \a i
    Positive(I& i);
    /// Initialize with values from \a i
    void init(I& i);
    //@}

    /// \name Iteration control
    //@{
    /// Test whether iterator is still at a value or done
    bool operator ()(void) const;
    /// Move iterator to next value (if possible)
    void operator ++(void);
    //@}

    /// \name Value access
    //@{
    /// Return current value
    int val(void) const;
    //@}
  };


  template<class I, bool strict>
  forceinline
  Positive<I,strict>::Positive(void) {}

  template<class I, bool strict>
  forceinline void
  Positive<I,strict>::init(I& i0) {
    i=i0;
    if (strict) {
      while (i() && (i.val() <= 0)) ++i;
    } else {
      while (i() && (i.val() < 0)) ++i;
    }
  }

  template<class I, bool strict>
  forceinline
  Positive<I,strict>::Positive(I& i0) : i(i0) {
    if (strict) {
      while (i() && (i.val() <= 0)) ++i;
    } else {
      while (i() && (i.val() < 0)) ++i;
    }
  }

  template<class I, bool strict>
  forceinline void
  Positive<I,strict>::operator ++(void) {
    ++i;
  }
  template<class I, bool strict>
  forceinline bool
  Positive<I,strict>::operator ()(void) const {
    return i();
  }

  template<class I, bool strict>
  forceinline int
  Positive<I,strict>::val(void) const {
    return i.val();
  }

}}}

// STATISTICS: iter-any

