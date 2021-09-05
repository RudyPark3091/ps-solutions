const solution = (n) =>
  parseInt(
    n
      .toString()
      .split("")
      .sort((a, b) => b.charCodeAt(0) - a.charCodeAt(0))
      .join("")
  );
