#define BOOST_TEST_MAIN
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include <memory>

const double EPSILON = 0.0001;



BOOST_AUTO_TEST_SUITE( A4_Throw )

  BOOST_AUTO_TEST_CASE( Matrix_Throw )
  {
    BOOST_CHECK_THROW( lyachko::Matrix matrix( nullptr, 4 ), std::invalid_argument );

    std::shared_ptr<lyachko::Matrix> matrix;
    lyachko::CompositeShape compositeshape;

    BOOST_CHECK_THROW( matrix = compositeshape.getMatrix(), std::invalid_argument );
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( A4_Rotation )

  BOOST_AUTO_TEST_CASE( RCT_Rotation )
  {
    std::shared_ptr<lyachko::Shape> rectangle( new lyachko::Rectangle( { { 1, 1 }, 4, 4 } ) );

    lyachko::rectangle_t r_original_frame = rectangle->getFrameRect();
    double r_original_area = rectangle->getArea();

    rectangle->rotate( 360 );

    BOOST_CHECK_CLOSE_FRACTION( r_original_area, rectangle->getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.x, r_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.y, r_original_frame.pos.y, EPSILON );

    rectangle->rotate( 0 );

    BOOST_CHECK_CLOSE_FRACTION( r_original_area, rectangle->getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.x, r_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.y, r_original_frame.pos.y, EPSILON );

    rectangle->rotate( 45 );

    BOOST_CHECK_CLOSE_FRACTION( r_original_area, rectangle->getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.x, r_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.y, r_original_frame.pos.y, EPSILON );

    rectangle->rotate( 45 );

    BOOST_CHECK_CLOSE_FRACTION( r_original_area, rectangle->getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.x, r_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.y, r_original_frame.pos.y, EPSILON );

    rectangle->rotate( 45 );

    BOOST_CHECK_CLOSE_FRACTION( r_original_area, rectangle->getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.x, r_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.y, r_original_frame.pos.y, EPSILON );

    rectangle->rotate( 45 );

    BOOST_CHECK_CLOSE_FRACTION( r_original_area, rectangle->getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.x, r_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( rectangle->getFrameRect().pos.y, r_original_frame.pos.y, EPSILON );
  }

  BOOST_AUTO_TEST_CASE( CMP_Rotation )
  {
    std::shared_ptr<lyachko::Shape> circle1( new lyachko::Circle( { { 1, 1 }, 2 } ) );
    std::shared_ptr<lyachko::Shape> circle2( new lyachko::Circle( { { 3, 3 }, 2 } ) );

    lyachko::CompositeShape compositeshape( circle1 );
    compositeshape.add( circle2 );

    lyachko::rectangle_t cmp_original_frame = compositeshape.getFrameRect();
    lyachko::point_t math_point = { 2, 2 };
    double cmp_original_area = compositeshape.getArea();

    BOOST_CHECK_CLOSE_FRACTION( compositeshape.getFrameRect().pos.x, math_point.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( compositeshape.getFrameRect().pos.y, math_point.y, EPSILON );

    compositeshape.rotate( 45 );

    BOOST_CHECK_CLOSE_FRACTION( cmp_original_area, compositeshape.getArea(), EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( compositeshape.getFrameRect().pos.x, cmp_original_frame.pos.x, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( compositeshape.getFrameRect().pos.y, cmp_original_frame.pos.y, EPSILON );

    compositeshape.rotate( -45 );

    BOOST_CHECK_CLOSE_FRACTION( compositeshape.getFrameRect().width, cmp_original_frame.width, EPSILON );
    BOOST_CHECK_CLOSE_FRACTION( compositeshape.getFrameRect().height, cmp_original_frame.height, EPSILON );
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( A4_Matrix )

  BOOST_AUTO_TEST_CASE( CMP_Matrix )
  {
    std::shared_ptr<lyachko::Matrix> matrix;
    lyachko::CompositeShape compositeshape;

    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle( { { 1, 1 }, 6, 6 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2(new lyachko::Rectangle( { { 3, 3 }, 2, 2 } ) );
    std::shared_ptr<lyachko::Shape> rectangle3(new lyachko::Rectangle( { { 7, 7 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle4(new lyachko::Rectangle( { { 15 , 15 }, 6, 6 }));

    compositeshape.add( rectangle1 );
    compositeshape.add( rectangle2 );
    compositeshape.add( rectangle3 );
    compositeshape.add( rectangle4 );

    size_t desired_layers = 2;
    size_t desired_size = 3;

    matrix = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix->infolayers(), desired_layers);
    BOOST_CHECK_EQUAL( matrix->infomaxsize(), desired_size);

  }

  BOOST_AUTO_TEST_CASE( CMP_Matrix_and_Rotation )
  {
    std::shared_ptr<lyachko::Matrix> matrix;
    lyachko::CompositeShape compositeshape;

    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2(new lyachko::Rectangle( { { 3, 1 }, 8, 1 } ) );

    compositeshape.add( rectangle1 );
    compositeshape.add( rectangle2 );

    size_t desired_layers = 2;
    size_t desired_size = 1;

    matrix = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix->infolayers(), desired_layers );
    BOOST_CHECK_EQUAL( matrix->infomaxsize(), desired_size );

    rectangle2->rotate( 90 );

    desired_layers = 1;
    desired_size = 2;

    matrix = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix->infolayers(), desired_layers );
    BOOST_CHECK_EQUAL( matrix->infomaxsize(), desired_size );
  }

  BOOST_AUTO_TEST_CASE( CMP_Matrix_and_Shifting )
  {
    std::shared_ptr<lyachko::Matrix> matrix1;
    std::shared_ptr<lyachko::Matrix> matrix2;
    lyachko::CompositeShape compositeshape;

    std::shared_ptr<lyachko::Shape> rectangle1( new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2( new lyachko::Rectangle( { { 3, 1 }, 8, 1 } ) );

    compositeshape.add( rectangle1 );
    compositeshape.add( rectangle2 );

    matrix1 = compositeshape.getMatrix();

    compositeshape.move( 4, 4 );

    matrix2 = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix1->infolayers(), matrix2->infolayers() );
    BOOST_CHECK_EQUAL( matrix1->infomaxsize(), matrix2->infomaxsize() );
  }

  BOOST_AUTO_TEST_CASE( CMP_Matrix_and_MovingTO )
  {
    std::shared_ptr<lyachko::Matrix> matrix1;
    std::shared_ptr<lyachko::Matrix> matrix2;
    lyachko::CompositeShape compositeshape;

    std::shared_ptr<lyachko::Shape> rectangle1( new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2( new lyachko::Rectangle( { { 3, 1 }, 8, 1 } ) );

    compositeshape.add( rectangle1 );
    compositeshape.add( rectangle2 );

    matrix1 = compositeshape.getMatrix();

    compositeshape.move( { 4, 4 } );

    matrix2 = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix1->infolayers(), matrix2->infolayers() );
    BOOST_CHECK_EQUAL( matrix1->infomaxsize(), matrix2->infomaxsize() );
  }

  BOOST_AUTO_TEST_CASE( RECT_Matrix_and_Shifting )
  {
    std::shared_ptr<lyachko::Matrix> matrix1;
    std::shared_ptr<lyachko::Matrix> matrix2;
    lyachko::CompositeShape compositeshape;

    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2(new lyachko::Rectangle( { { 3, 1 }, 8, 1 } ) );

    compositeshape.add( rectangle1 );
    compositeshape.add( rectangle2 );

    matrix1 = compositeshape.getMatrix();

    rectangle1->move( 4, 4 );

    matrix2 = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix1->infolayers(), matrix2->infomaxsize() );
    BOOST_CHECK_EQUAL( matrix1->infomaxsize(), matrix2->infolayers() );
  }

  BOOST_AUTO_TEST_CASE( RECT_Matrix_and_MovingTo )
  {
    std::shared_ptr<lyachko::Matrix> matrix1;
    std::shared_ptr<lyachko::Matrix> matrix2;
    lyachko::CompositeShape compositeshape;

    std::shared_ptr<lyachko::Shape> rectangle1( new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2( new lyachko::Rectangle( { { 3, 1 }, 8, 1 } ) );

    compositeshape.add( rectangle1 );
    compositeshape.add( rectangle2 );

    matrix1 = compositeshape.getMatrix();

    rectangle1->move( { 5, 5 } );

    matrix2 = compositeshape.getMatrix();

    BOOST_CHECK_EQUAL( matrix1->infolayers(), matrix2->infomaxsize() );
    BOOST_CHECK_EQUAL( matrix1->infomaxsize(), matrix2->infolayers() );
  }

BOOST_AUTO_TEST_SUITE_END()
