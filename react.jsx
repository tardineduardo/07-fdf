import React, { useState } from 'react';

const IsometricDemo = () => {
  // Previous state and constants remain unchanged
  const [transitionProgress, setTransitionProgress] = useState(0);
  
  const gridHeight = 5;
  const gridWidth = 9;
  const cellSize = 40;
  const centerX = Math.floor(gridWidth / 2);
  const centerY = Math.floor(gridHeight / 2);
  const gridWidthPx = gridWidth * cellSize;
  const gridHeightPx = gridHeight * cellSize;
  
  // Vector definitions [x, y] in grid units
  const vectors = {
    red: [-4, 2],
    yellow: [-4, -2],
    green: [1, 1],
    pink: [2, -1]
  };
  
  // All helper functions remain the same
  const generatePoints = () => {
    const points = [];
    const tempPoints = [];
    
    for (let y = 0; y < gridHeight; y++) {
      for (let x = 0; x < gridWidth; x++) {
        const relX = (x - centerX) * cellSize;
        const relY = (y - centerY) * cellSize;
        const isoX = (relX - relY) * Math.cos(Math.PI/6);
        const isoY = (relX + relY) * Math.sin(Math.PI/6);
        tempPoints.push({ isoX, isoY });
      }
    }
    
    const isoXs = tempPoints.map(p => p.isoX);
    const isoYs = tempPoints.map(p => p.isoY);
    const isoWidth = Math.max(...isoXs) - Math.min(...isoXs);
    const isoHeight = Math.max(...isoYs) - Math.min(...isoYs);
    
    const scaleX = gridWidthPx / isoWidth;
    const scaleY = gridHeightPx / isoHeight;
    const scale = Math.min(scaleX, scaleY) * 0.8;
    
    for (let y = 0; y < gridHeight; y++) {
      for (let x = 0; x < gridWidth; x++) {
        const relX = (x - centerX) * cellSize;
        const relY = (y - centerY) * cellSize;
        const isoX = (relX - relY) * Math.cos(Math.PI/6) * scale;
        const isoY = (relX + relY) * Math.sin(Math.PI/6) * scale;
        points.push({ x: relX, y: relY, isoX, isoY });
      }
    }
    return { points, scale };
  };

  const { points, scale } = generatePoints();

  const getCurrentPoints = () => {
    return points.map(point => ({
      x: point.x + (point.isoX - point.x) * transitionProgress,
      y: point.y + (point.isoY - point.y) * transitionProgress
    }));
  };

  const getVectorEndpoint = (vector) => {
    const [x, y] = vector;
    const endX = x * cellSize;
    const endY = y * cellSize;
    const isoX = (endX - endY) * Math.cos(Math.PI/6) * scale;
    const isoY = (endX + endY) * Math.sin(Math.PI/6) * scale;
    
    return {
      x: endX + (isoX - endX) * transitionProgress,
      y: endY + (isoY - endY) * transitionProgress,
      origX: endX,
      origY: endY,
      isoX: isoX,
      isoY: isoY
    };
  };

  const getArrowHead = (end, start = { x: 0, y: 0 }) => {
    const dx = end.x - start.x;
    const dy = end.y - start.y;
    const angle = Math.atan2(dy, dx);
    const length = 10;
    const angle1 = angle + Math.PI / 6;
    const angle2 = angle - Math.PI / 6;

    return {
      x1: end.x - length * Math.cos(angle1),
      y1: end.y - length * Math.sin(angle1),
      x2: end.x - length * Math.cos(angle2),
      y2: end.y - length * Math.sin(angle2)
    };
  };
  
  const viewWidth = gridWidthPx;
  const viewHeight = gridHeightPx;

  const vectorColors = {
    red: '#FF0000',
    yellow: '#CC9900',
    green: '#008000',
    pink: '#FF69B4'
  };

  const formatCoord = (x, y) => `${(x/cellSize).toFixed(1)}, ${(y/cellSize).toFixed(1)}`;
  
  return (
    <div className="w-full max-w-4xl p-4">
      <div className="mb-4 flex flex-col gap-2">
        <div className="flex items-center gap-4">
          <span className="text-sm font-medium">Top View</span>
          <input 
            type="range" 
            min="0" 
            max="100" 
            value={transitionProgress * 100} 
            onChange={(e) => setTransitionProgress(e.target.value / 100)}
            className="w-full"
          />
          <span className="text-sm font-medium">Isometric</span>
        </div>
        <div className="text-center text-sm text-gray-600">
          Transition: {Math.round(transitionProgress * 100)}%
        </div>
      </div>
      
      <svg 
        viewBox={`${-viewWidth/2} ${-viewHeight/2} ${viewWidth} ${viewHeight}`}
        className="w-full border border-gray-300 bg-gray-100"
      >
        {/* Draw original grid (ghost) */}
        {points.map((point, i) => {
          const isCenter = Math.abs(point.x) < 1 && Math.abs(point.y) < 1;
          return (
            <g key={`ghost-${i}`}>
              <circle 
                cx={point.x} 
                cy={point.y} 
                r={isCenter ? 2 : 1}
                fill={isCenter ? 'rgba(255,0,0,0.1)' : 'rgba(0,0,0,0.1)'}
              />
              {(i % gridWidth !== gridWidth - 1) && (
                <line
                  x1={point.x}
                  y1={point.y}
                  x2={points[i+1].x}
                  y2={points[i+1].y}
                  stroke="rgba(0,0,0,0.1)"
                  strokeWidth="0.5"
                />
              )}
              {i < points.length - gridWidth && (
                <line
                  x1={point.x}
                  y1={point.y}
                  x2={points[i+gridWidth].x}
                  y2={points[i+gridWidth].y}
                  stroke="rgba(0,0,0,0.1)"
                  strokeWidth="0.5"
                />
              )}
            </g>
          );
        })}
        
        {/* Draw current grid */}
        {getCurrentPoints().map((point, i) => {
          const isCenter = Math.abs(point.x) < 1 && Math.abs(point.y) < 1;
          return (
            <g key={i}>
              <circle 
                cx={point.x} 
                cy={point.y} 
                r={isCenter ? 2 : 1}
                fill={isCenter ? 'red' : 'black'}
              />
              {(i % gridWidth !== gridWidth - 1) && (
                <line
                  x1={point.x}
                  y1={point.y}
                  x2={getCurrentPoints()[i+1].x}
                  y2={getCurrentPoints()[i+1].y}
                  stroke="#222222"
                  strokeWidth="0.5"
                  opacity="0.8"
                />
              )}
              {i < points.length - gridWidth && (
                <line
                  x1={point.x}
                  y1={point.y}
                  x2={getCurrentPoints()[i+gridWidth].x}
                  y2={getCurrentPoints()[i+gridWidth].y}
                  stroke="#222222"
                  strokeWidth="0.5"
                  opacity="0.8"
                />
              )}
            </g>
          );
        })}

        {/* Draw vectors with arrows and coordinates */}
        {Object.entries(vectors).map(([color, vector]) => {
          const end = getVectorEndpoint(vector);
          const arrowHead = getArrowHead(end);
          return (
            <g key={color}>
              {/* Original position (ghost) */}
              <line
                x1={0}
                y1={0}
                x2={end.origX}
                y2={end.origY}
                stroke="rgba(0,0,0,0.1)"
                strokeWidth="1.5"
              />
              {/* Current vector */}
              <line
                x1={0}
                y1={0}
                x2={end.x}
                y2={end.y}
                stroke={vectorColors[color]}
                strokeWidth="1.5"
              />
              <line
                x1={arrowHead.x1}
                y1={arrowHead.y1}
                x2={end.x}
                y2={end.y}
                stroke={vectorColors[color]}
                strokeWidth="1.5"
              />
              <line
                x1={arrowHead.x2}
                y1={arrowHead.y2}
                x2={end.x}
                y2={end.y}
                stroke={vectorColors[color]}
                strokeWidth="1.5"
              />
              {/* Coordinates with background */}
              <rect
                x={end.x + 5}
                y={end.y - 16}
                width="45"
                height="14"
                fill="white"
                opacity="0.8"
                rx="2"
              />
              <text
                x={end.x + 8}
                y={end.y - 5}
                fill={vectorColors[color]}
                fontSize="6"
                fontFamily="monospace"
              >
                {formatCoord(end.x, end.y)}
              </text>
            </g>
          );
        })}
      </svg>
    </div>
  );
};

export default IsometricDemo;