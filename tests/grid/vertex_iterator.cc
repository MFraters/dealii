// ---------------------------------------------------------------------
//
// Copyright (C) 2015 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------


// test TriaAccessor<0,dim,spacedim>


#include "../tests.h"
#include <deal.II/grid/tria.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/grid_generator.h>

#include <fstream>


void test ()
{
  Triangulation<2> tria;
  GridGenerator::hyper_cube (tria);
  tria.refine_global (2);

  for (typename Triangulation<2>::active_cell_iterator
       cell = tria.begin_active(); cell != tria.end(); ++cell)
    {
      for (unsigned int i = 0; i<4; ++i)
        deallog << cell->vertex_it(i)->center() <<std::endl;
    }
}



int main ()
{
  std::ofstream logfile("output");
  deallog.attach(logfile);
  deallog.depth_console(0);

  test ();

  return 0;
}
